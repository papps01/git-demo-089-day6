#include <iostream>
#include <thread>
#include <mutex>

int amount =1000;

std::mutex m1;

void withdraw(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        // critical section start
        m1.lock();
        amount-=10;
        // critical section end
        m1.unlock();
    }
}


void Deposit(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));

        //critical section start
        m1.lock();
        amount+=10;
        //critical section end 
        m1.unlock();
    }
}


int main(){
    std::thread t1(&withdraw);
    std::thread t2(&Deposit);
    t1.join();
    t2.join();

    std::cout<<"Final Amount: "<<amount <<std::endl;
}