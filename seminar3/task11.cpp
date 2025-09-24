#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << std::fixed << std::setprecision(2) << sqrt(a*a + b*b);
    return 0;
}