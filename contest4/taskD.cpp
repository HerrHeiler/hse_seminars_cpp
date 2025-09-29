#include <iostream>

int main() {
    int a;
    std::cin >> a;
    int* p = &a;
    int** pp = &p;
    std::cout << a << ' ' << *p << ' ' << **pp;
    return 0;
}