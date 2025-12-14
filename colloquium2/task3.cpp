#include <iostream>

int* first_occurrence(int* arr, int n, int x, int* index) {
    for (int a = 0; a < n; ++a) {
        if (arr[a] == x) {
            *index = a;
            return &arr[a];
        }
    }
    *index = -1;
    return nullptr;
}

int main() {
    int n, x;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) std::cin >> arr[i];
    std::cin >> x;
    int index;
    int* pX = first_occurrence(arr, n, x, &index);
    std::cout << index << std::endl;
    for (uint i = index; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    return 0;
}