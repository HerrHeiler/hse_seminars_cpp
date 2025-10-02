#include <iostream>


// 0 0      0 1      0 2      0 3
// 1 0      1 1      1 2      1 3
// 2 0      2 1      2 2      2 3
// 3 0      3 1      3 2      3 3
int main() {
    int n, s;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s = i + j;
            if (s == (n - 1)) {
                std::cout << '1';
            } else if (s < (n - 1)) {
                std::cout << '0';
            } else {
                std::cout << '2';
            }
            if (j == (n - 1)) std::cout << '\n';
            else std::cout << ' ';
        }
    }
    return 0;
}