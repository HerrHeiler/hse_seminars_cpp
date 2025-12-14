#include <iostream>


void swap(int* a, int* b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    swap(&a, &b);
    std::cout << a << ' ' << b;
    return 0;
}