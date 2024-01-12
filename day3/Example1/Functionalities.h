#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <memory>
#include "Employee.h"
#include "BusinessOwner.h"
#include <variant>
using   BusinessPtr=std::shared_ptr<BusinessOwner>;

using  EmpPtr=std::shared_ptr<Employee>;

using  VType=std::variant<EmpPtr,BusinessPtr>;

using  Container=std::vector<VType>;

void CreateObject(Container& data)
{
    data.emplace_back(
        std::shared_ptr<Employee>()
    );



}
/* to access anything from a variant you have to use std::visit */

#endif // FUNCTIONALITIES_H
