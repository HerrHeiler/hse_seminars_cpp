#include <iostream>

int main() {
    int num = 0;
    while (std::cin >> num, num != -1) {
        for (int i = 0; i <= num; i += 2) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}