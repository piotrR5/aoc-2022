#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

bool doTheyContains(pair<int,int>a, pair<int,int>b){
    auto [a1,a2]=a;
    auto [b1,b2]=b;
    if((a1>= b1 && a2<=b2) || (a1<=b1 && a2>=b2))return true;
    return false;
}

bool doTheyOverlap(pair<int,int>a, pair<int,int>b){
    auto [a1,a2]=a;
    auto [b1,b2]=b;
    if((a2<b1) ||(a1>b2))return false;
    return true;
}

int main(){
    fstream file;
    file.open("input.txt");
    string line;
    int count1=0, count2=0;

    while(file>>line){
        int a1,a2,b1,b2;
        stringstream ss;
        line.replace(line.find_first_of(','), 1, " ");
        line.replace(line.find_first_of('-'), 1, " ");
        line.replace(line.find_first_of('-'), 1, " ");
        ss<<line;
        ss>>a1>>a2>>b1>>b2;
        if(doTheyContains({a1,a2}, {b1,b2}))count1++;
        if(doTheyOverlap({a1,a2},{b1,b2}))count2++;
    }    

    cout<<count1<<endl;
    cout<<count2<<endl;
    
}
