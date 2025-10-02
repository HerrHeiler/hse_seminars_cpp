#include <iostream>

int main() {
    int n;
    int m;
    std::cin >> n >> m;
    int** s= new int* [n];

    for (int i = 0; i < n; ++i) s[i] = new int[m]();

    int k = 0;
    int kr = 1;
    for (int i = 0; i < m; ++i){
        for (int j = kr-1; j >= 0; --j){
            s[i-j][j] = k;
            ++k;
        }
        ++kr;
    }
    --kr;
    for (int i = m; i < n; ++i){
        for (int j = kr-1; j >= 0; --j){
            s[i-j][j] = k;
            ++k;
        }
    }
    --kr;
    for (int i = 1; i < m; ++i){
        for (int j = kr-1; j >= 0; --j){
            s[n-j-1][i+j] = k;
            ++k;
        }
        --kr;
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            std::cout << s[i][j];
            if (j != m-1) {
                std::cout << ' ';
            } else {
                std::cout << '\n';
            }
        }
    }

    for (int i = 0; i < n; ++i){
        delete[] s[i];
    }
    return 0;
}
