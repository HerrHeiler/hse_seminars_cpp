#include <iostream>

int main() {
    int N, s = 0;
    std::cin >> N;
    if (N < 0) {
        N = -N;
    }
    while (N > 0) {
        s += N%10;
        N /= 10;
    }
    std::cout << s;
    return 0;
}