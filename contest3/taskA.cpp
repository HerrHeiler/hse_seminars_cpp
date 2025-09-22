#include <iostream>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (x2 == x1 || y2 == y1 || (x2 - y2) == (x1 - y1)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}