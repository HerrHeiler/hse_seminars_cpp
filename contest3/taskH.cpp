#include <iostream>

int main() {
    int n, r, t, a;
    std::cin >> n;
    r = 0;
    a = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> t;
        if (i == 0) {
            a = t;
            r = 1;
        }
        if (a == t) {
            r++;
        } else {
            r--;
        }
        if (r == 0) {
            a = t;
            r = 1;
        }
    }
    std::cout << a;
    return 0;
}