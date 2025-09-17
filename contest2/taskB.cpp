#include <iostream>

int main() {
    int x, i, one_bit, shifted_num;
    one_bit = 1;
    std::cin >> x >> i;
    shifted_num = x >> i;
    std::cout << (one_bit&shifted_num);
    return 0;
}