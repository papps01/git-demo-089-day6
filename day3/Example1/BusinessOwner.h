#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H

#include <iostream>
class BusinessOwner
{
private:
    /* data */
public:
    BusinessOwner(/* args */) {}
    ~BusinessOwner() {}

    void payTax(){
        std::cout<<"Business owner hass to pay advance tax\n";
    }
};

#endif // BUSINESSOWNER_H
