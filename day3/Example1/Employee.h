#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
private:
    
public:
    Employee(/* args */) {}

    ~Employee() {}

    void payTax(){
        std::cout<<"Employee has to pay TDS \n";
    }

};

#endif // EMPLOYEE_H
