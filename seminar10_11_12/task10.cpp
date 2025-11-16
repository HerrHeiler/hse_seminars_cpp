#include <iostream>
#include <string>


enum class Role {
    ENGINEER, 
    MANAGER,
    HR, 
    SECURITY, 
    INTERN
};

struct Employee {
    std::string name;
    int id;
    Role role;
    float salary;
};

std::string _role_to_string(Role _role) {
    switch(_role) {
        case Role::ENGINEER : return "Engineer";
        case Role::HR : return "HR";
        case Role::INTERN : return "Intern";
        case Role::MANAGER : return "Manager";
        case Role::SECURITY : return "Security";
    };
    
}