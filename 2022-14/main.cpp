#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unistd.h>


using namespace std;

#define VOID 0 
#define WALL 1
#define SAND 2

#define sizeX 1200

void printSpace(vector<vector<int>>&space){
    for(auto i:space){
        for(auto j:i)cout<<(j==0? '.' : (j==1 ? '#' : (j==2 ? 'o' : 'X')));
        cout<<endl;
    }
    cout<<endl;
}

vector<tuple<int,int,int,int>>splitIntoLines(string l){

    vector<tuple<int,int,int,int>>returned;
    while(l.find_first_of("->")!=string::npos){
        l.erase(l.find_first_of('-'), 2);
    }

    while(l.find_first_of(",")!=string::npos){
        l[l.find_first_of(',')]=' ';
    }

    int nowx, nowy, prevx, prevy;
    stringstream ss;
    ss<<l;
    ss>>nowx>>nowy;
    prevx=nowx;
    prevy=nowy;
    while(ss>>nowx>>nowy){
        returned.push_back({prevx, prevy, nowx, nowy});
        prevx=nowx;
        prevy=nowy;
    }
    
    return returned;
}

int sign(int a){
    return (a>0 ? 1 : (a<0 ? -1 : 0));
}

void setWall(tuple<int,int,int,int>wall, vector<vector<int>>&space){
    auto [x1,y1,x2,y2]=wall;
    if(x2-x1!=0){
        for(int i=x1;i!=x2+sign(x2-x1);i+=sign(x2-x1)){
            space[y1][i+(sizeX/2-500)]=WALL;
            //cout<<i<<" "<<y1<<endl;
        }
    }else{
        for(int i=y1;i!=y2+sign(y2-y1);i+=sign(y2-y1)){
            space[i][x1+(sizeX/2-500)]=WALL;
            //cout<<x1<<" "<<i<<endl;
        }
    }
    
}

void setWalls(string l, vector<vector<int>>&space){
    
    auto w=splitIntoLines(l);
    for(auto i:w)setWall(i, space);
    
}

bool sandTouchingBottom(vector<vector<int>>&space){
    for(int i=0;i<sizeX;i++){
        if(space[163][i]==SAND){
            space[163][i]=VOID;
            return true;
        }
    }
    return false;
}

bool move(vector<vector<int>>&space, bool didMove){
    if(!didMove)space[0][500+(sizeX/2-500)]=SAND;
    didMove=false;
    for(int i=0;i<sizeX;i++){
        for(int j=0;j<165;j++){
            if(space[j][i]==SAND){
                if(space[j+1][i]==VOID){
                    space[j][i]=VOID;
                    space[j+1][i]=SAND;
                    
                }else if(space[j+1][i-1]==VOID){
                    space[j][i]=VOID;
                    space[j+1][i-1]=SAND;
                    didMove=true;
                }else if(space[j+1][i+1]==VOID){
                    space[j][i]=VOID;
                    space[j+1][i+1]=SAND;
                    didMove=true;
                }
            }
        }
    }
    return didMove;
}

int main(){
    //ios::sync_with_stdio(false);
    fstream file;
    string line;
    vector<vector<int>>space(165,vector<int>(sizeX,VOID));
    space[164]=vector<int>(sizeX, -1);
    vector<tuple<int,int,int,int>>walls;

    file.open("input.txt");
    while(getline(file,line)){
        //cout<<line<<endl;
        setWalls(line, space);
    }

    //printSpace(space);
    bool didMove=false;
    while(!sandTouchingBottom(space)){
        didMove=move(space, didMove);
        //printSpace(space);
        //usleep(1600000);
        //system("clear");
    }

    
    int c=0;

    for(auto i:space){
        for(auto j:i)if(j==SAND)c++;
    }


    cout<<endl<<endl;
    cout<<"["<<(int)c<<"]\n";
    //usleep(10000000);

    vector<vector<int>>space2=space;
    space2[164]=vector<int>(sizeX, WALL);

    didMove=false;

    printSpace(space2);

    // while(space2[0][500]==VOID){
    //     didMove=move(space2, didMove);
    //     //printSpace(space2);
    //     //system("clear");
    // }

    // int c2=0;

    // for(auto i:space2){
    //     for(auto j:i)if(j==SAND)c2++;
    // }

    
    // cout<<"["<<c2<<"]\n";

    

    return 0;
}