#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>

using namespace std;

string itoa5(uint64_t n)
{
    string ret="";
    while(n){
        ret+=to_string(n%5);
        n/=5;
    }

    return string(ret.rbegin(), ret.rend());
} 

uint64_t getDec(string n){
    uint64_t num=0;
    uint64_t pow=1;
    n=string(n.rbegin(), n.rend());
    for(auto i:n){
        switch(i){
            case '1':{
                num+=(pow*1);
            }
            break;
            case '2':{
                num+=(pow*2);
            }
            break;
            case '0':{
                num+=(pow*0);
            }
            break;
            case '-':{
                num+=(pow*-1);
            }
            break;
            case '=':{
                num+=(pow*-2);
            }
            break;
        }

        pow*=5;
    }

    return num;
}



string toWeird(uint64_t n){
    string foo=itoa5(n);
    for(int i=foo.size()-1;i>0;i--){
        if(foo[i]=='3'){
            foo[i]='=';
            foo[i-1]++;
        }
        if(foo[i]=='4'){
            foo[i]='-';
            foo[i-1]++;
        }
        if(foo[i]=='5'){
            foo[i]='0';
            foo[i-1]++;
        }
    }
    return foo;
}

int main(){
    fstream file;
    file.open("input.txt");
    string line;
    vector<pair<string,uint64_t>>data;
    while(getline(file,line)){
        data.push_back({line, getDec(line)});
    }

    uint64_t count1=0;

    for(auto [a,b]:data){
        cout<<"["<<a<<" "<<b<<"]\n";
        count1+=b;
    }

    cout<<"1: "<<count1<<endl;
    cout<<toWeird(count1)<<endl;
}
