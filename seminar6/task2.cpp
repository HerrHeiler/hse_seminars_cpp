#include <iostream>
#include <string>

int main() {
    std::string i;
    std::cin >> i;
    if (i[0] == '-') {
        std::cout << '-';
        i.erase(0, 1);
    }
    for (int j = i.length() - 1; j >= 0; --j) {
        std::cout << i[j];
    }
    return 0;
}