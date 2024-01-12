/*
    create  an array of 5 that calq8 the square
        of One Number From an array of 5 interger
*/

#include <array>
#include <iostream>
#include <thread>
#include <functional>
void InstantiateThread(
    std::array<std::thread,5>&threadArr,
    std::function<void(int,int)>f1,
    std::array<int,5>&data){
    auto itr = data.begin();

    for (int i=0;i<5;i++)
    {
        threadArr[i] = std::thread(f1, *itr++,i);
    }

}

void JoinThread(std::array<std::thread,5>&threadArr){
    for (std::thread &t : threadArr)
    {

        if (t.joinable())
        {
            t.join();
        }
    }
}
void  DisplayResult(std::array<int,5>&result,std::array<int,5>&data){

    for(int val:result){
        std::cout<< "Square of Number : "<< val <<"\n";
    }
}
void startapp()
{

    std::array<int, 5> data{10, 20, 30, 40, 50};
    std::array<int, 5> result;

    
    auto f1 = [&](int number,int idx)
    { result[idx] = number * number; };

    std::array<std::thread, 5> threadArr;
    InstantiateThread(threadArr,f1,data);
    JoinThread(threadArr);
    DisplayResult(result,data);
}


int main()
{
    startapp();   
}
