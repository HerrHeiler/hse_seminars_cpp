#include <iostream>

void inversed() {
    int k, temp;
    std::cin >> k;
    //int* permut = new int[k];
    int* right = new int[k];
    for (int i = 0; i < k; ++i) {
        std::cin >> temp;
        right[temp - 1] = i + 1;
    }
    for (int j = 0; j < k; ++j) std::cout << right[j] << ' ';
    //for (int i = 0; i < k; ++i) delete[] permut[i];
}

int main() {
    inversed();
    return 0;
}