#include <iostream>
#include <vector>
#include <deque>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        seq[i] = temp;
    }
    std::deque<int> deka;
    for (int i = 0; i < n; ++i) {
        while ((!deka.empty()) && (seq[deka.back()] >= seq[i])) deka.pop_back();
        deka.push_back(i);
        if ((!deka.empty()) && (deka.front() <= (i - k))) deka.pop_front();
        if (i >= (k - 1)) std::cout << seq[deka.front()] << '\n';
    }
    return 0;
}
