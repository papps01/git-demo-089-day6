#include<iostream>
#include <vector>
#include <optional>

void TakeInput(std::vector<int>&data,int N){
    int val=-1;
    while(N>0){
        std::cin>>val; 
        data.push_back(val);
        N--;
    }
}

std::optional<std::vector<int>> ReturnEvenNumber(std::vector<int>& data){
    if(data.empty()){
        throw std::runtime_error("Empty Data");
    }
    std::vector<int>result;
    for(int v:data){
        if(v%2==0){
            result.push_back(v);
        }
    }
    if(result.empty()){
        return std::nullopt;
    }
    return result;

}

int main(){
    int N=-1;
    std::cin>> N ;
    std::vector<int>v1(N);
    std::vector<int>data;
    TakeInput(data,N);

    std::optional<std::vector<int>> evennumber=ReturnEvenNumber(data);

    if(evennumber.has_value()){
        std::cout<< evennumber.value().size();
    }
    else
    {
        std::cout<< "No Even value Found" <<"\n";
    }
    

}