#include <iostream>
#include <iomanip>

int main() {
    float a = 4567.2984;
    std::cout << std::fixed << std::setprecision(3) << a << std::endl;
    std::cout << std::oct << a << std::endl;
    std::cout << std::dec << a << std::endl;
    return 0;
}