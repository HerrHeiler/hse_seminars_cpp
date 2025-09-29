#include <iostream>

int main() {
    int an, b, p_sum;
    std::cin >> an >> b;
    int* p1 = &an;
    int* p2 = &b;
    p_sum = *p1 + *p2;
    *p1 = p_sum - *p1;
    *p2 = p_sum - *p2;
    std::cout << an << ' ' << b;
    return 0;
}