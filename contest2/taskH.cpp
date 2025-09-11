#include <iostream>

int main() {
    int friends, pieces;
    std::cin >> friends >> pieces;
    std::cout << pieces/(friends + 1);
    return 0;
}