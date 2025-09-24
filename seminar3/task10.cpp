#include <iostream>

int main() {
    int a;
    std::cin >> a;
    if (a & 1) std::cout << "odd";
    else std::cout << "even";
}