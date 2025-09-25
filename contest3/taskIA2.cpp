#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, cnt = 1;
    std::cin >> n;
    std::vector <int> numbers(n);
    for (int i = 0; i < n; ++i) std::cin >> numbers[i];
    std::sort(numbers.begin(), numbers.end());
    for (int i = 1; i <= n; ++i) {
        if (i < n && numbers[i] == numbers[i-1]) {
            ++cnt;
        } else {
            if(cnt == 1 || cnt == 2) {
                std::cout << numbers[i-1] << ' ' << cnt << '\n';
                break;
            }
            cnt = 1;
        }
    }
    return 0;
}
