#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int n1 = n;
    int** s= new int* [n];
    for (int i = 0; i < n; ++i){
        s[i] = new int[n]();
    }
    for (int k=0; k<n; k+=2){
        int l = k;
        int r = n - k-1;
        int top = k;
        int down = n - k-1;

        for (int i = l; i <= r; ++i){
            s[top][i] = 1;
        }

        for (int i = top; i <= down; ++i){
            s[i][r] = 1;
        }
        if (down-1 != top) {
        for (int i = l; i <= r; ++i){
            s[down][i] = 1;
        }}
        for (int i = top + 2; i <= down; ++i){
            s[i][l] = 1;
        }

    }

    int j = 1;
    for (int i = 2; i <= n/2; i += 2){
        s[i][j] = 1;
        j += 2;
    }

    for (int i = 0; i < n1; ++i){
        for (int j = 0; j < n1; ++j){
            std::cout << s[i][j];
        }
        std::cout << '\n';
    }
    for (int i = 0; i < n1; ++i){
        delete[] s[i];
    }
    delete[] s;
    return 0;
}
