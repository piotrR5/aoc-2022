#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void printImg(vector<int64_t>vec){
        for(int j=0;j<240;j++){
            if(vec[j]%40+1==j%40 || vec[j]%40==j%40 || vec[j]%40-1==j%40)cout<<"#";

            else cout<<".";
            if(j%40==39)cout<<endl;
        }//cout<<(vec[40*i+j]==40*i+j+1 ? "#" : ".");
       cout<<endl;
    
}

int main(){
    fstream file;
    file.open("input.txt");
    int64_t x=1;
    vector<int64_t>xByTime;
    xByTime.push_back(x);
    string line;
    while(getline(file, line)){
        if(line.find("noop")!=string::npos){
            xByTime.push_back(x);
            //cout<<"noop\t"<<line.back()<<"\t"<<line.size()-1<<endl;
        }
        if(line.find("addx")!=string::npos){
            
            stringstream ss;
            ss<<line;
            string foo;
            int64_t n;
            ss>>foo>>n;
            //cout<<n<<endl;
            xByTime.push_back(x);
            x+=n;
            xByTime.push_back(x);
            //cout<<"addx\t"<<(int)line[line.size()-1]<<"\t"<<"["<<n<<"]\t"<<line.size()-1<<endl;
        }
        //cout<<"[[ size: "<<xByTime.size()<<" ]]\n";
    }
    vector<int64_t>out(6, 0);
    out[0]=xByTime[19]*20;
    out[1]=xByTime[99]*100;
    out[2]=xByTime[139]*140;
    out[3]=xByTime[179]*180;
    out[4]=xByTime[219]*220;
    out[5]=xByTime[59]*60;
    int64_t out1=0;
    for(auto i:out)out1+=i;
    cout<<"part1: "<<out1<<endl;

    printImg(xByTime);
}
