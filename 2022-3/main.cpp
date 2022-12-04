#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <tuple>

using namespace std;

void increment(map<char,int>&m, char key){
    if(m.find(key)==m.end())m.insert({key, 1});
    else m.at(key)++;
}

int priorityOf(char c){
    if(c>='a' && c<='z'){
        return c-'a'+1;
    }
    return c-'A'+27;
}

char findBadLetter(string l, string r){
    map<char, int>countLettersL;
    map<char, int>countLettersR;
    for(auto i:l){
        increment(countLettersL, i);
    }
    for(auto i:r){
        increment(countLettersR, i);
    }

    for(auto [key,val]: countLettersL){
        //cout<<key<<" "<<val<<endl;
        if(countLettersR.find(key)!=countLettersR.end())return key;
    }
    return 0;
}

char findLetterOfPriority(int p){
    if(p<27)return p+'a'-1;
    return p+'A'-27;
}

char findBadge(tuple<string,string,string>group){
    vector<vector<int>>count(3, vector<int>(52,0));
    auto [a,b,c]=group;
        for(auto i:a){
            count[0][priorityOf(i)-1]++;
        }
        for(auto i:b){
            count[1][priorityOf(i)-1]++;
        }
        for(auto i:c){
            count[2][priorityOf(i)-1]++;
        }

    for(int i=0;i<52;i++){
        if(count[0][i]>0 && count[1][i]>0 && count[2][i]>0)return findLetterOfPriority(i+1);
    }
    return 0;
}



int main(){
    fstream file;
    file.open("input.txt");
    string line;
    vector<pair<string,string>>lines;
    int prioritySum=0;
    while(file>>line){
        lines.push_back({string(line.begin(), line.begin()+line.size()/2), string(line.begin()+line.size()/2, line.end())});
    }

    for(auto [r,l]: lines){
        prioritySum+=priorityOf(findBadLetter(l,r));
    }

    cout<<prioritySum<<endl;

    prioritySum=0;

    for(int i=2;i<lines.size();i+=3){
        string a=lines[i].first+lines[i].second;
        string b=lines[i-1].first+lines[i-1].second;
        string c=lines[i-2].first+lines[i-2].second;
        prioritySum+=priorityOf(findBadge({a,b,c}));
    }
    cout<<prioritySum<<endl;
}
