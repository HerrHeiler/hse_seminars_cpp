#include <iostream>

int main() {
    int A, i;
    std::cin >> A >> i;
    std::cout << (A ^ (1 << i));
    return 0;
}