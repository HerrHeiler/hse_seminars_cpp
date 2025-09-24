#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    a ^= b;
    b ^= a;
    a ^= b;
    std::cout << a << ' ' << b;
    return 0;
}