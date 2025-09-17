#include <iostream>

int main() {
    int A, n;
    std::cin >> A >> n;
    std::cout << ((A)&((2 << (n - 1)) - 1));
    return 0;
}