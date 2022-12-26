#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void move(std::vector<std::pair<int64_t,int>>&vec){
    int index=0;
    int d=0;
    std::pair<int64_t,int>arg({0,0});
    for(int i=0;i<vec.size();i++){
        if(!vec[i].second){
            index=i;
            arg=vec[i];
            arg.second=1;
            d=(index+arg.first);
            //std::cout<<"[ "<<vec[i].first<<" "<<index<<" "<<d<<" ]\n";
            if(d<0){
                //std::cout<<"CHUJ\n";
                while(d<0)d+=vec.size();
                d--;
            }
            if(d>vec.size()-1){
                d=d%(vec.size()-1);
                //d++;
            }
             
            
            //std::cout<<"[ "<<vec[i].first<<" "<<index<<" "<<d<<" ]\n";
            break;
        }
    }
    if(d==0)d=vec.size()-1;

    vec.erase(vec.begin()+index);
    vec.emplace(vec.begin()+d, arg);

    for(auto [a,b]: vec)std::cout<<a<<"\n";
    std::cout<<"\n";
}

int find(std::vector<std::pair<int64_t,int>>vec, int f){
    for(int i=0;i<vec.size();i++)if(vec[i].first==f)return i;
}

int main(){
    std::fstream file;
    file.open("input.txt");
    std::vector<std::pair<int64_t,int>>encrypted;
    int in;
    while(file>>in)encrypted.push_back({in, 0});

    std::vector<std::pair<int64_t,int>>encrypted2=encrypted;

    //for(auto [a,b]: encrypted)std::cout<<a<<"\n";
    //std::cout<<"\n";

    for(int i=0;i<encrypted.size();i++)move(encrypted);

    //for(auto [a,b]: encrypted)std::cout<<a<<"\n";
    // std::cout<<"\n";
    // std::cout<<"\n";

    int zero=find(encrypted, 0);
    std::cout<<encrypted[(zero+1000)%encrypted.size()].first+encrypted[(zero+2000)%encrypted.size()].first+encrypted[(zero+3000)%encrypted.size()].first<<"\n";



//part 2

    // for(auto& [a,b]:encrypted2)a*=811589153;

    // std::cout<<"[["<<(int)2/7<<"]]\n";

    // std::cout<<"Initial arrangement: \n";
    // for(auto [a,b]: encrypted2)std::cout<<a<<" ";
    // std::cout<<"\n";

    // for(int k=0;k<10;k++){
    //     for(int i=0;i<encrypted2.size();i++)move(encrypted2);
    //     for(int i=0;i<encrypted2.size();i++)encrypted2[i].second=0;
    //     std::cout<<"after round: "<<k<<"\n";
    //     for(auto [a,b]: encrypted2)std::cout<<a<<" ";
    //     std::cout<<"\n";
    // }

    // zero=find(encrypted2, 0);

    // std::cout<<encrypted2[(zero+1000)%encrypted2.size()-1].first+encrypted2[(zero+2000)%encrypted2.size()-1].first+encrypted2[(zero+3000)%encrypted2.size()-1].first<<"\n";

    return 0;
}