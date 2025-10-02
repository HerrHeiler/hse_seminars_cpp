#include <iostream>

int main() {
    int n;
    int m;
    std::cin >> n >> m;
    int **s= new int*[n];
    for (int i = 0; i < n; ++i){
        s[i] = new int[m]();
    }

    for (int i = 0; i < n; ++i){
        s[i][0] = 1;
    }

    for (int j = 0; j < m; ++j){
        s[0][j] = 1;
    }

    for (int i = 1; i < n; ++i){
        for (int j = 1; j < m; ++j){
            s[i][j] = s[i-1][j] + s[i][j-1];
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            std::cout << s[i][j];
            if (j != m-1) {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }

    for (int i = 0; i < n; ++i){
        delete[] s[i];
    }

    return 0;
}
