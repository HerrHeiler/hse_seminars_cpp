#include <iostream>

int main() {
    float y;
    std::cin >> y;
    float *p = &y;
    std::cin >> *p;
    std::cout << y;
}