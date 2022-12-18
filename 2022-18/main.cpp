#include <bits/stdc++.h>
using namespace std;

#define SIZE 20

vector<tuple<int,int,int>>getAdjCubes(tuple<int,int,int>c, vector<vector<vector<int>>>& space){
    auto [x,y,z]=c;
    vector<tuple<int,int,int>>ret;
    if(x>0){
        if(!space[x-1][y][z])ret.push_back({x-1,y,z});
    }
    if(x+1<SIZE){
        if(!space[x+1][y][z])ret.push_back({x+1,y,z});
    }
    if(y>0){
        if(!space[x][y-1][z])ret.push_back({x,y-1,z});
    }
    if(y+1<SIZE){
        if(!space[x][y+1][z])ret.push_back({x,y+1,z});
    }
    if(z>0){
        if(!space[x][y][z-1])ret.push_back({x,y,z-1});
    }
    if(z+1<SIZE){
        if(!space[x][y][z+1])ret.push_back({x,y,z+1});
    }
    return ret;
}

void BFS3D(vector<vector<vector<int>>>& space){
    deque<tuple<int,int,int>> q;
    space[0][0][0]=1;
    q.push_back({0,0,0});
    while(!q.empty()){
        auto a=getAdjCubes(q.back(), space);
        auto [x,y,z]=q.back();
        space[x][y][z]=1;
        q.pop_back();
        
        for(auto i:a)q.push_back(i);
    }

}

int nOfAdjCubes(tuple<int,int,int>c, vector<vector<vector<int>>> space){
    auto [x,y,z]=c;
    int n=0;
    if(x>0){
        if(space[x-1][y][z])n++;
    }
    if(x+1<SIZE){
        if(space[x+1][y][z])n++;
    }
    if(y>0){
        if(space[x][y-1][z])n++;
    }
    if(y+1<SIZE){
        if(space[x][y+1][z])n++;
    }
    if(z>0){
        if(space[x][y][z-1])n++;
    }
    if(z+1<SIZE){
        if(space[x][y][z+1])n++;
    }
    return n;
}

void showPlane(vector<vector<int>> space){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            cout<<(char)(space[i][j] ? '#' : '.'); 
        }
        cout<<endl;
    }
}

int calcArea(vector<tuple<int,int,int>>cubes){
    vector<vector<vector<int>>> space(SIZE, vector<vector<int>>(SIZE, vector<int>(SIZE, 0)));

    for(int i=0;i<SIZE;i++)for(int j=0;j<SIZE;j++)for(int k=0;k<SIZE;k++)space[i][j][k]=0;

    int area=0;
    for(auto [x,y,z]:cubes){
        space[x][y][z]=1;
    }

    // for(int i=0;i<SIZE;i++){
    //     showPlane(space[i]);
    // }

    for(int x=0;x<SIZE;x++){
        for(int y=0;y<SIZE;y++){
            for(int z=0;z<SIZE;z++){
                if(space[x][y][z]){
                    area+=6-nOfAdjCubes({x,y,z}, space);
                }
            }
        }
    }

    cout<<area<<endl;

    BFS3D(space);

    int area2=0;

    // for(int i=0;i<SIZE;i++){
    //     showPlane(space[i]);
    // }

    for(int x=0;x<SIZE;x++){
        for(int y=0;y<SIZE;y++){
            for(int z=0;z<SIZE;z++){
                if(space[x][y][z]){
                    area2+=6-nOfAdjCubes({x,y,z}, space);
                }
            }
        }
    }

    cout<<area+(6*SIZE*SIZE)-area2<<endl;
}

int main(){
    fstream file;
    file.open("input.txt");
    vector<tuple<int,int,int>>cubes;
    string line;
    while(getline(file,line)){
        while(line.find(",")!=string::npos){
            line[line.find(",")]=' ';
        }

        tuple<int,int,int>in;
        auto& [a,b,c]=in;
        stringstream ss;
        ss<<line;;
        ss>>a>>b>>c;
        cubes.push_back(in);
    }

    calcArea(cubes);

    


    return 0;
}
