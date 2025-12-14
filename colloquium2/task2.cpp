#include <iostream>
#include <vector>

void print(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << arr[n-1];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    print(arr.data(), n);
    return 0;
}