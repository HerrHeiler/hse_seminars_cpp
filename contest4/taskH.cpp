#include <iostream>

int main() {
    int n;
    int m;

    std::cin >> n >> m;

    int **s= new int*[std::max(n, m)];
    for (int i=0; i<std::max(n, m); ++i){
        s[i] = new int[std::min(n, m)]();
    }
    if (n >= m){
    int k = 0;
    int kr = 1;
    for (int i = 0; i < std::min(n, m); ++i){
        for (int j = kr-1; j >= 0; j--){
            s[i-j][j] = k;
            ++k;
        }
        ++kr;
    }
    --kr;
    for (int i = std::min(n, m); i < std::max(n, m); ++i){
        for (int j = kr-1; j >= 0; j--){
            s[i-j][j] = k;
            ++k;
        }
    }
    --kr;
    for (int i = 1; i < std::min(n, m); ++i){
        for (int j = kr-1; j >= 0; j--){
            s[std::max(n, m)-j-1][i+j] = k;
            // std::cout << n << ' ' << i << ' ' << j << ' ' << k << ' ' << n-i+j << '\n';
            ++k;
        }
        --kr;
    }
} else {
    int k = 0;
    int kr = 1;
    for (int i = 0; i < std::min(n, m); ++i){
        for (int j = 0; j < kr; ++j){
            s[i-j][j] = k;
            ++k;
        }
        ++kr;
    }
    --kr;
    for (int i = std::min(n, m); i < std::max(n, m); ++i){
        for (int j = 0; j < kr; ++j){
            s[i-j][j] = k;
            ++k;
        }
    }
    --kr;
    for (int i = 1; i < std::min(n, m); ++i){
        for (int j = 0; j < kr; ++j){
            s[std::max(n, m)-j-1][i+j] = k;
            // std::cout << n << ' ' << i << ' ' << j << ' ' << k << ' ' << n-i+j << '\n';
            ++k;
        }
        --kr;
    }
}

    if (std::max(n, m) == n){
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            std::cout << s[i][j];
            if (j != m-1) {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
    }
    else {
        for (int j=0; j<n; ++j){
        for (int i=0; i<m; ++i){

            std::cout << s[i][j];
            if (j != m-1) {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
    }

    for (int i=0; i<n; ++i){
        delete[] s[i];
    }
    return 0;
}
