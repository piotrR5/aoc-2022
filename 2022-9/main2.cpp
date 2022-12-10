#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

#define SIZE 30

using namespace std;

void align(pair<int,int>&h, pair<int,int>&t){
    auto& [xh,yh]=h;
    auto& [xt,yt]=t;
    if(xt+1<xh){
        xt++;
        yt=yh;
    }
    if(xt-1>xh){
        xt--;
        yt=yh;
    }
    if(yt+1<yh){
        yt++;
        xt=xh;
    }
    if(yt-1>yh){
        yt--;
        yh=yt;
    }
}

void doAMove(vector<pair<int,int>>&rope, char dir, int n,
             vector<vector<bool>> &vis) {
    int dx = 0, dy = 0;
    switch (dir) {
    case 'U':
        dy = 1;
        break;
    case 'D':
        dy = -1;
        break;
    case 'R':
        dx = 1;
        break;
    case 'L':
        dx = -1;
    }

    //cout << "[" << dir << " " << n << "]\n";

    while (n--) {
        for(auto [x,y]:rope){
                //cout<<"["<<x<<", "<<y<<"]\n";
        }

        rope[0].first-=dy;
        rope[0].second+=dx;

        for(int i=1;i<10;i++){
            align(rope[i-1], rope[i]);
        }
        vis[rope[9].first+SIZE/2][rope[9].second+SIZE/2]=true;

        // for(int i=1;i<10;i++){
            
        //     //auto p = rope[i-1];
        //     rope[i-1].first += dx;
        //     rope[i-1].second += dy;
        //     vis[rope[9].first + 500][rope[9].second + 500] = true;
            
        //         if (rope[i].first + 1 < rope[i-1].first) {
        //             rope[i].first++;
        //             rope[i].second=rope[i-1].second;
        //             //rope[i] = p;
        //         }
        //         if (rope[i].first - 1 > rope[i-1].first) {
        //             //rope[i] = p;
        //             rope[i].first--;
        //             rope[i].second=rope[i-1].second;
        //         }
        //         if (rope[i].second + 1 < rope[i-1].second) {
        //             //rope[i] = p;
        //             rope[i].second++;
        //             rope[i].first=rope[i-1].first;
        //         }
        //         if (rope[i].second - 1 > rope[i-1].second) {
        //             //rope[i] = p;
        //             rope[i].second--;
        //             rope[i].first=rope[i-1].first;
        //         }
        //         //p=rope[i];
        // }
        
        //vis[t.first + 500][t.second + 500] = true;
    }
}

int main(int argc, char *argv[]) {
    fstream file;
    file.open("test.txt");
    string line;
    vector<pair<int, int>> rope;
    rope.push_back({0, 0});
    rope.push_back({0, 0});
    rope.push_back({0, 0});
    rope.push_back({0, 0});
    rope.push_back({0, 0});
    rope.push_back({0, 0});
    rope.push_back({0, 0});
    rope.push_back({0, 0});
    rope.push_back({0, 0});
    rope.push_back({0, 0});
    vector<vector<bool>> vis(SIZE, vector<bool>(SIZE, 0));

    char dir;
    int n;

    while (file >> dir >> n) {
            cout<<"["<<dir<<" "<<n<<"]\n";
            doAMove(rope, dir, n, vis); 
            
            vector<vector<bool>> deb(SIZE, vector<bool>(SIZE, 0));
            for(auto [a,b]:rope)deb[a+SIZE/2][b+SIZE/2]=1;
            for(auto i:deb){
                for(auto j:i)cout<<(j? "#": ".");
                cout<<endl;
            }
        
    }

    int c = 0;
    for (auto &i : vis) {
        for (auto j : i) {
            cout<<(j ? 'X':'.');
            c += j;
        }
        cout<<endl;
    }
    cout << c << endl;
}