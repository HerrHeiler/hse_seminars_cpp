#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int* pN = &n;
    std::cout << "Input: " << *pN << '\n' << "Output: " << '\n';
    for (int i = 0; i < 1; ++i) {
        for (int j = 1; j <= 10; ++j) {
            std::cout << n << " x " << j << " = " << (*pN * j) << '\n';
        }
    }
    return 0;
}