#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include<tuple>

using namespace std;

string cleanUpLine(string s){
    for(auto& i:s){
        if((i>'9' || i<'0') && 
        (i<'A' || i>'Z'))i=' ';
    }
    return s;
}

bool containsJustSpace(string s){
    if(s.find_first_not_of(' ',0)==string::npos)return true;
    return false;
}

bool containsJustLetters(string s){
    for(auto i:s)if(i<'A' || i>'Z')return false;
    return true;
}

void doAMove(vector<string>&s, tuple<int,int,int>m){
    auto [n,a,b]=m;
    int index=s[a-1].size()-n;
    string temp(s[a-1].rbegin()+index, s[a-1].rend());
    
    s[b-1]+=string(temp.rbegin(),temp.rend());
    s[a-1]=string(s[a-1].begin(), s[a-1].begin()+index);
}

void doAMove2(vector<string>&s, tuple<int,int,int>m){
    auto [n,a,b]=m;
    int index=s[a-1].size()-n;
    string temp(s[a-1].begin()+index, s[a-1].end());
    
    s[b-1]+=string(temp.begin(),temp.end());
    s[a-1]=string(s[a-1].begin(), s[a-1].begin()+index); 
}

void printStacks(vector<string>s){
    for(auto i:s)cout<<i<<endl;
}

void printMove(tuple<int,int,int>t){
    auto [a,b,c]=t;
    cout<<a<<" "<<b<<" "<<c<<endl;
}

int main(){
    fstream file;
    file.open("input.txt");
    string line;
    vector<string>stacks={
        "PFMQWGRT",
        "HFR",
        "PZRVGHSD",
        "QHPBFWG",
        "PSMJH",
        "MZTHSRPL",
        "PTHNML",
        "FDQR",
        "DSCNLPH"
    };

    vector<string>stacks2=stacks;
    vector<tuple<int,int,int>>moves;
    int chuj=0;
    while(getline(file,line)){
        string s=cleanUpLine(line);
        //cout<<cleanUpLine(line)<<endl;
        string kutas;
        if(chuj>9){
            stringstream ss;
            ss<<line;
            int a,b,c;
            ss>>kutas>>a>>kutas>>b>>kutas>>c;
            moves.push_back({a,b,c});
        }
        chuj++;
    }
    
    for(auto i:moves)doAMove(stacks,i);
    for(auto i:moves)doAMove2(stacks2,i);
    printStacks(stacks);
    cout<<endl;
    printStacks(stacks2);
} 