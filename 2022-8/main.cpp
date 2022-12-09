#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void printVec(vector<vector<int>>v){
    for(auto i:v){
        for(auto j:i)cout<<j;
        cout<<endl;
    }
}

void printBoolVec(vector<vector<bool>>v){
    for(auto i:v){
        for(auto j:i)cout<<j;
        cout<<endl;
    }
}

int main(){
    fstream file;
    file.open("input.txt");
    string line;
    vector<vector<int>>matrix;
    while(getline(file,line)){
        vector<int>l;
        for(auto i:line){
            l.push_back(i-'0');
        }
        matrix.push_back(l);
    }

    vector<vector<bool>>v(matrix.size(), vector<bool>(matrix[0].size(), 0));

    int sizeX=matrix.size();
    int sizeY=matrix[0].size();

    printVec(matrix);
    printBoolVec(v);


    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            v[i][0]=true;
            v[i][sizeY-1]=true;
            v[0][j]=true;
            v[sizeX-1][j]=true;
        }
    }


    

   

    cout<<endl;
    printBoolVec(v);

    int c=0;

    for(auto i:v){
        for(auto j:i)c+=j;
    }

    cout<<c<<endl;
}
