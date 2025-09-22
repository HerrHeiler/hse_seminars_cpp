#include <iostream>


int main() {
    int n, res = 0, temp;
    std::cin >> n;
    for(int i = 1; i <= n+1; ++i) {
        res ^= i;
        temp = 0;
        if (i <= n) std::cin >> temp;
        res ^= temp;
    }
    std::cout << res;
    return 0;
}
