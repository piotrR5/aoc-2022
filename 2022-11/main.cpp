#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#define M 2*3*5*7*11*13*17*19*23

uint64_t modAdd(uint64_t a, uint64_t b){
    return ((a) + (b%M)) %M;
}

uint64_t modMult(uint64_t a, uint64_t b){
    return ((a)* (b%M)) %M;
}

uint64_t modPow(uint64_t a){
    return ((a)* (a%M)) %M;
}

struct monke{
    vector<int>items;
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
    //cout<<nums<<endl;
    while(nums.find(",")!=string::npos){
        i=nums.find(",");
        nums.erase(i, 1);
    }
    //cout<<nums<<endl;
    vector<uint64_t>returned;

    int n;

    stringstream ss;
    ss<<nums;
    while(ss>>n){
        returned.push_back(n);
    }
    return returned;
}

void round(vector<monke>&vec, vector<int>&monkeBuisness){

    for(int k=0;k<vec.size();k++){
        auto& m=vec[k];
        m.printMonke();
        monkeBuisness[k]+=m.items.size();
        for(int i=0;i<m.items.size();i++){
            switch(m.operation){
                case '^':
                m.items[i]=modPow(m.items[i]);
                break;
                case '*':
                m.items[i]=modMult(m.items[i], m.operand);
                break;
                case '+':
                m.items[i]=modAdd(m.items[i], m.operand);
            }
            if(m.items[i]%m.test==0){
                vec[m.ifTrue].items.push_back(m.items[i]);
            }else{
                vec[m.ifFalse].items.push_back(m.items[i]);
            }

            m.items.erase(m.items.begin()+i, m.items.begin()+i+1);

        }
    }
    // for(auto& m:vec){
        
    // }
}

int main(){
    fstream file;
    file.open("test.txt");
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

    // for(auto i:monkes){
    //     i.printMonke();
    // }

    vector<int>monkeB(monkes.size(), 0);

    for(int i=1;i<21;i++){
        cout<<"ROUND "<<i<<"!!!\n";
        
        //for(auto j:monkes)j.printMonke();

        round(monkes, monkeB);

    }

    for(auto i:monkes)i.printMonke();

    for(auto i:monkeB)cout<<i<<" ";
    cout<<endl;

}
