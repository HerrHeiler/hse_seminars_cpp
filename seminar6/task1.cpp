#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    arr[0] = 0; arr[1] = 1; arr[2] = 1;
    for (int i = 3; i < n; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    for (int j = 0; j < n; ++j) {
        std::cout << arr[j] << ' ';
    }
    return 0;
}