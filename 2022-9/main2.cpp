#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <algorithm>

#define SIZE 1000

using namespace std;

#define UP 4
#define DOWN 5
#define RIGHT 6
#define LEFT 7

void printRope(vector<pair<int,int>>rope){
    system("clear");
    auto [x,y]=rope[0];
    vector<vector<bool>>g(SIZE, vector<bool>(SIZE,0));
        for(auto [a,b]: rope){
            g[a+SIZE/2][b+SIZE/2]=true;
        }

        g[x+SIZE/2][y+SIZE/2]=2;

    for(auto i:g){
        for(auto j:i){
            cout<<(j==1?"#":".");
            //cout<<(j==2?"O":".");
        }
        cout<<endl;
    }
    usleep(200000);
}

void move(vector<pair<int,int>>&rope, char dir){

    switch(dir){
        case 'U':
            rope[0].second++;
        break;

        case 'D':
            rope[0].second--;
        break;
            
        case 'R':
            rope[0].first++;
        break;

        case 'L':
            rope[0].first--;
        break;
    }

    for(int i=1;i<10;i++){
        pair<int,int>& f=rope[i];
        pair<int,int>& p=rope[i-1];

        if(f.second == p.second){
            int dx=p.first-f.first;
            if(abs(dx)>1){
                f.first+=(dx < 0) ? -1 : (dx > 0);
                // cout<<"first if\n";
                // usleep(1000000);
            }
        }else if(f.first==p.first){
            int dy=p.second-f.second;
            if(abs(dy)>1){
                f.second+=(dy < 0) ? -1 : (dy > 0);
                // cout<<"second if\n";
                // usleep(1000000);
            }
        }else {
            pair<int,int> d({p.first-f.first, p.second-f.second});
            pair<int,int> absd({abs(d.first), abs(d.second)});
            if(absd.first>1 || absd.second>1){
                // int sx=0, sy=0;
                // if(d.first>0)sx=1;
                // else if(d.first<0)sx=-1;
                // if(d.second>0)sy=1;
                // else if(d.second<0)sy=-1;

                f.first+=(d.first < 0) ? -1 : (d.first > 0);
                f.second+=(d.second < 0) ? -1 : (d.second > 0);
                // cout<<"third if\n";
                // usleep(1000000);
            }
            
        }
    }
}



int main(int argc, char *argv[]) {
    fstream file;
    file.open("input.txt");
    string line;
    vector<pair<int, int>> rope(10, pair<int,int>({0,0}));
    vector<vector<bool>> vis(SIZE, vector<bool>(SIZE, 0));

    char dir;
    int n;

    //cout<<"["<<rope[9].first<<" "<<rope[9].second<<"]\n";
    rope[9].first=0;
    rope[9].second=0;


    while(file>>dir>>n){
        cout<<"["<<dir<<" "<<n<<"]\n";
        for(int i=0;i<n;i++){
            move(rope, dir);
            //printRope(rope);
            vis[rope[9].first+SIZE/2][rope[9].second+SIZE/2]=1;
        }
        cout<<"["<<rope[9].first<<" "<<rope[9].second<<"]\n";
    }

    int c=0;
    for(auto i:vis){
        for(auto j:i)c+=j;
    }

    cout<<c<<endl;

    
}