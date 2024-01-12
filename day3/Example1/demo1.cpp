#include "Employee.h"
#include "BusinessOwner.h"
#include <variant>
#include <memory>

int main(){
    std::variant<Employee,BusinessOwner>v1;
    
    v1= Employee();
/* 
    visit need 2 parameters 
    First: Lambda function to indicate what ti do with item inside variant
        second: object of variant class
*/
    std::visit(
        [](auto&& val){val.payTax();},v1
    );

    v1= BusinessOwner();

    std::visit(
        [](auto&& val){val.payTax();},v1
    );

    std::shared_ptr<Employee>e1=std::make_shared<Employee>();

    std::variant< std::shared_ptr<Employee>,std::shared_ptr<BusinessOwner> >v2;

    v2=e1; //storing e1 inside the variant

    std::visit(
        [](auto&& val){val->payTax();},
        v2
    );
}
