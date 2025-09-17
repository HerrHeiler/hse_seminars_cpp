#include <iostream>

int main() {
    int integer, first, second, third, fourth;
    std::cin >> integer;
    fourth = integer%10;
    integer /= 10;
    third = integer%10;
    integer /= 10;
    second = integer%10;
    integer /= 10;
    first = integer%10;
    integer /= 10;
    if (fourth == first && third == second) {
        std::cout << 1;
    } else {
        std::cout << 2;
    }
    return 0;
}