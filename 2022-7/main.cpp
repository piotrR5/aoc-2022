#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <sstream>
#include <memory>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

void printGraph(vector<vector<int>>adj, vector<string>dirs){
    for(int i=0;i<adj.size();i++){
        cout<<i<<": ";
        for(int j=0;j<adj[i].size();j++){
            //cout<<dirs[j]<<" ";
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    fstream file;
    file.open("input.txt");
    string line;

    vector<vector<int>>adj;
    vector<int>chuj;
    adj.push_back(chuj);
    vector<string>dirs(1, "/");
    vector<uint64_t>sizes(1, 0);
    int current=0;
    int count=0;

    while(getline(file,line)){
        cout<<"["<<line<<"]\n";
        if(line.find("$")!=string::npos){
            if(line.find("cd")!=string::npos){
                if(line.find("..")!=string::npos){
                    for(int i=0;i<adj.size();i++){
                        for(int j=0;j<adj[i].size();j++){
                            if(adj[i][j]==current){
                                current=i;
                                break;
                            }
                            
                        }
                    }
                }else{
                    for(auto i:dirs){
                        cout<<i<<endl;
                    }
                    
                    string dir(line.begin()+5, line.end());
                    for(int i=0;i<adj[current].size();i++){
                        //cout<<dirs[adj[current][i]]<<endl;
                        if(dirs[adj[current][i]]==dir){
                            current=adj[current][i];
                            break;
                        }
                    }
                    
                }
            }
        }else{
            if(line.find("dir")!=string::npos){
                dirs.push_back(string(line.begin()+4, line.end()));
                vector<int>chuj;
                adj.push_back(chuj);
                adj[current].push_back(adj.size()-1);
                //cout<<"CHUJ\n";
                sizes.push_back(0);
                // for(auto i:adj){
                //     //cout<<i<<endl;
                //     for(auto j:i)cout<<j<<" ";
                //     cout<<endl;
                // }
            }else{
                stringstream ss;
                ss<<line;
                uint64_t size;
                ss>>size;
                sizes[current]+=size;

            }
        }
    }

    for(int i=sizes.size()-1;i>=0;i--){
        if(adj[i].empty()){
            continue;
        }

        for(auto a:adj[i]){
            sizes[i]+=sizes[a];
        }
    }

    printGraph(adj, dirs);

    uint64_t total=0;

    for(auto i:sizes){
        cout<<i<<endl;
        if(i<=100000)total+=i;
    }

    cout<<total<<endl;

    uint64_t unusedSpace=70000000-sizes[0];

    sort(sizes.begin(),sizes.end());

    for(auto i:sizes){
        if(unusedSpace+i>=30000000){
            cout<<"["<<i<<endl;
        }
    }
    

    return 0;
}