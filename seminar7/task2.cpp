#include <iostream>
#include <thread>
#include <cstdlib>
#include <random>

int main() {
    int n = 5, m = 5, delay;
    int** matrix = new int* [n];
    for (int i = 0; i < m; i++) matrix[n] = new int[m]();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[n][m] = rand()%10;
            std::cout << matrix[n][m] << ' ';
            if (j == (m - 1)) std::cout << '\n';
        }
    }
    int s = 1;
    while (s <= 10) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == (m - 1)) std::cout << "\x1b[A" << '\r' << matrix[n][m] << std::flush;
                else std::cout << matrix[n][m] << ' ';
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                //if (j == (m - 1) && s == 1) std::cout << '\n';
                //std::cout << '\r';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[n][m] *= 2;
            }
        }
        ++s;
    }
    return 0;
}