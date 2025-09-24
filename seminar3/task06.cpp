#include <iostream>

int main() {
    int a, s = 0;
    std::cin >> a;
    if (a < 0) a = -a;
    while (a > 0) {
        s += a % 10;
        a /= 10;
    }
    std::cout << s;
    return 0;
}