#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << (a | b) << '\n' << (a & b) << '\n' << (a ^ b) << '\n' << (a >> 1) << '\n' << (a << 1) << '\n' << (~a);
    return 0;
}