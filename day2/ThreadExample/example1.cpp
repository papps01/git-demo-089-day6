/*
     Create a thread t1 that calculate square  of all numbers
        in an array and stores them in result container
*/

#include <iostream>
#include <thread>
#include <array>
std::array<int,5>result;
int main(){
    std::array<int,5> data{1,2,3,4,5};
    /* Create  and Initiate t1 */

    std::thread t1(
        [](std::array<int,5>&data){
            int k=0;

            for(int val:data)
            {
                result[k++]=val*val;
            }
        },
        std::ref(data)
    );
    t1.join();
    for(int val :result){
        std::cout << "square of numbers :"<<val<<"\n";
    }
}