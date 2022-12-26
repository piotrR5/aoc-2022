#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

uint64_t M=2*3*5*7*11*13*17*19*23;

uint64_t modAdd(uint64_t a, uint64_t b){
    //return a+b;
    return ((a%M) + (b%M)) %M;
}

uint64_t modMult(uint64_t a, uint64_t b){
    //return a*b;
    return ((a%M)* (b%M)) %M;
}

uint64_t modPow(uint64_t a){
    //return a*a;
    return ((a%M)* (a%M)) %M;
}

struct monke{
    vector<uint64_t>items;
    char operation;
    int operand;
    int test;
    int ifTrue;
    int ifFalse;

    void printMonke(){
        cout<<"[items: ";
        for(auto i:items)cout<<i<<" ";
        cout<<"]\n";
        cout<<"[operation: "<<operation<<" "<<operand<<"]\n";
        cout<<"[test: "<<test<<" "<<ifTrue<<" "<<ifFalse<<"]\n";
        cout<<"\n"; 
    }

    monke(){

    }
};

vector<uint64_t>extractNums(string nums){
    int i;
    while(nums.find(",")!=string::npos){
        i=nums.find(",");
        nums.erase(i, 1);
    }
    vector<uint64_t>returned;

    uint64_t n;

    stringstream ss;
    ss<<nums;
    while(ss>>n){
        returned.push_back(n);
    }
    return returned;
}

void round(vector<monke>&vec, vector<uint64_t>&monkeBuisness){
    for(int k=0;k<vec.size();k++){
        auto& m=vec[k];
        monkeBuisness[k]+=m.items.size();
    
        while(m.items.empty()==false){
            auto& i=m.items[0];

            switch(m.operation){
                case '^':
                i=modPow(i);
                break;
                case '*':
                i=modMult(i, m.operand);
                break;
                case '+':
                i=modAdd(i, m.operand);
            }
            //i/=3;

            if(i%m.test==0){
                vec[m.ifTrue].items.push_back(i);
            }else{
                vec[m.ifFalse].items.push_back(i);
            }
            m.items.erase(m.items.begin());
        }
    }

    for(auto i:vec){
        i.printMonke();
    }
}

int main(){
    fstream file;
    file.open("input.txt");
    string line;

    vector<monke>monkes;

    while(getline(file,line)){
        if(line.find("Monkey")!=string::npos){
            monkes.push_back(monke());
        }if(line.find("items")!=string::npos){
            string a,b;
            int n;
            stringstream ss;
            ss<<line;
            ss>>a>>b;
            string nums;
            getline(ss, nums);
            vector<uint64_t>numbers=extractNums(nums);
            for(auto i:numbers)monkes[monkes.size()-1].items.push_back(i);
            
        }

        if(line.find("Operation")!=string::npos){
            string a,b,c,d, operation, operand;
            int n;
            stringstream ss;
            ss<<line;
            ss>>a>>b>>c>>d>>operation>>operand;
            if(operand=="old"){
                monkes[monkes.size()-1].operation='^';
                monkes[monkes.size()-1].operand=0;
            }else{
                monkes[monkes.size()-1].operation=operation[0];
                monkes[monkes.size()-1].operand=stoi(operand);
            }
                
        }

        if(line.find("Test")!=string::npos){
            string a,b,c;
            int n;
            stringstream ss;
            ss<<line;
            ss>>a>>b>>c>>n;
            monkes[monkes.size()-1].test=n;
        }
        if(line.find("true")!=string::npos){
            stringstream ss;
            ss<<line;
            string a,b,c,d,e;
            int n;
            ss>>a>>b>>c>>d>>e>>n;
            monkes[monkes.size()-1].ifTrue=n;
        }
        if(line.find("false")!=string::npos){
            stringstream ss;
            ss<<line;
            string a,b,c,d,e;
            int n;
            ss>>a>>b>>c>>d>>e>>n;
            monkes[monkes.size()-1].ifFalse=n;
        }
    }

    vector<uint64_t>monkeB(monkes.size(), 0);

    for(int i=1;i<10001;i++){
        cout<<"ROUND "<<i<<"!!!\n";
        round(monkes, monkeB);
    }

    for(auto i:monkes)i.printMonke();

    sort(monkeB.begin(), monkeB.end());

    for(auto i:monkeB)cout<<i<<" ";
    cout<<endl;
    cout<<monkeB[monkeB.size()-2]*monkeB[monkeB.size()-1]<<endl;

}
