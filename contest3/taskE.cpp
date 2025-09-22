#include <iostream>

int main() {
    int cnt = 32;
    for (int i = 1; i <= 7; ++i) {
        for (int j = 0; j <= 16; ++j) {
            if (i == 1 && j == 0) {
                std::cout << '\t';
            } else if (i == 1) {
                char k = j + 54;
                if (j <= 10) std::cout << j-1 << '\t';
                else if (j == 16) std::cout << k << '\n';
                else std::cout << k << '\t';
            } else if (j == 0) {
                std::cout << i << '\t';
            } else {
                char c = cnt;
                if (j == 16) std::cout << c << '\n';
                else std::cout << c << '\t';
                if (++cnt == 128) break;
            }
        }
    }
    return 0;
}