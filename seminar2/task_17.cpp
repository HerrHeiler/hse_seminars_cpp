#include <iostream>

int main() {
    double x = 1.0/0.0;
    double y = 0.0/0.0;
    std::cout << (x > 0) << " " << (x == x) << " " << (y == y) << '\n';
    return 0;
}