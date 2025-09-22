#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n+1; ++i) {
        for (int j = 1; j <= n+1; ++j) {
            if (i == 1 && j == 1) {
                std::cout << '\t';
            } else if (i == 1) {
                if (j == n+1) std::cout << j-1 << '\n';
                else std::cout << j-1 << '\t';
            } else if (j == 1) {
                std::cout << i-1 << '\t';
            } else if (j == n+1) {
                std::cout << ((i-1)*(j-1))%m  << '\n';
            } else {
                std::cout << ((i-1)*(j-1))%m << '\t';
            }
        }
    }
    return 0;
}