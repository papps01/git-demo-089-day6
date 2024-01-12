#include <iostream>
#include <array>
#include <thread>
std::array<int, 10> result;
void square(std::array<int, 5> &data)
{
    int k = 0;
    for (int val : data)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        result[k++] = val * val;
    }
}

void cube(std::array<int, 5> &data)
{
    int k = 5;
    for (int val : data)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        result[k++] = val * val * val;
    }
}
int main()
{
    std::array<int, 5> data{1, 2, 3, 4, 5};

    std::thread t1(&square, std::ref(data));
    std::thread t2(&cube, std::ref(data));

    t1.join();//blocking the main function until t1 is finished
    t2.join();//blocking the main function until t2 is finished

    for (int val : result)
    {
        std::cout << val << "        ";
    }
}
/* #->Parallelzising 
    #->thread
    #->this_thread
    
     
*/