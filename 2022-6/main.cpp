#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include<tuple>

using namespace std;

bool meetsSubroutine(char a,char b,char c,char d){
	if(a!=b && a!=c  && a!=d && b!=c && b!=d && c!=d)return true;
	return false;
}

bool isDistinctive(string s){
	//cout<<s.size()<<endl;
	vector<int>c(26,0);
	for(auto i:s)c[i-'a']++;
	for(auto i:c)if(i>1)return false;
	return true;
}

int main(){
    fstream file;
    file.open("input.txt");
    string line;

    while(getline(file,line)){
         for(int i=3;i<line.size();i++)if(meetsSubroutine(line[i-3], line[i-2], line[i-1],line[i])){
         	
         	cout<<i+1<<endl;
         	break;
         }
         
         for(int i=13;i<line.size();i++){
         	string temp=string(line.begin()+i-13,line.begin()+i+1);
         	if(isDistinctive(temp)){
         		cout<<i+1<<endl;
         		break;
         	}
         }
    }

}
