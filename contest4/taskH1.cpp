#include <iostream>

int main() {
    int n;
    int m;
    std::cin >> n >> m;
    int** s= new int* [n];

    for (int i = 0; i < n; ++i) s[i] = new int[m]();

    int k = 0;
    int kr = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //s[]
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << s[i][j];
            if (j != m-1) std::cout << ' ';
            else std::cout << '\n';
        }
    }

    for (int i = 0; i < n; ++i){
        delete[] s[i];
    }
    return 0;
}
