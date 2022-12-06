#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <tuple>

using namespace std;

void makeStacks(vector<vector<char>>temp, vector<string>&s){
    s=vector<string>(9, string(8,'x'));
    for(int i=0;i<8;i++){
        for(int j=0;j<9;j++){
            if(temp[i][j]!=' ')s[j][i]=temp[i][j];
        }
    }

    for(int i=0;i<9;i++){
        while(s[i].find_first_of('x')!=string::npos){
            s[i].erase(s[i].find_first_of('x'), 1);
        }
    }

    for(auto& i:s){
        i=string(i.rbegin(), i.rend());
    }
}

void printStacks(vector<string>s){
    cout<<"Stacks: "<<endl;
    for(auto i:s)cout<<i<<endl;
}

void printMoves(vector<tuple<int,int,int>>m){
    cout<<"Moves: "<<endl;
    for(auto [n,a,b]: m)cout<<n<<" from "<<a<<" to "<<b<<endl;
}

int main(){
    fstream file;
    file.open("input.txt");
    string line;
    vector<vector<char>>temporaryCrates;
    vector<string>stacks;
    vector<tuple<int,int,int>>moves;
    int counter=0;
    while(getline(file, line)){
        //crates are on indexes
        //1 5 9 13 17 21 25 29 33
        if(counter++<8){
            temporaryCrates.push_back({line[1], line[5], line[9], line[13], line[17], line[21], line[25], line[29], line[33]});
            continue;
        }
        if(counter++<12)continue;
        string foo;
        int a,b,c;
        
        stringstream ss;
        ss<<line;
        ss>>foo>>a>>foo>>b>>foo>>c;
        moves.push_back({a,b,c});
    }
    makeStacks(temporaryCrates, stacks);
    //cout<<"CHUJ\n";
    printStacks(stacks);
    printMoves(moves);
    printStacks(stacks);
}
