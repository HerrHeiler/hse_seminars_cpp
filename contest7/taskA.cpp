#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string alpha;
    std::cin >> alpha;
    std::unordered_set<char> beta;
    for (int i = 0; i < alpha.length(); ++i) beta.insert(alpha[i]);
    int N;
    std::cin >> N;
    while (N != 0) {
        std::string word;
        std::cin >> word;
        bool f = true;
        for (char c : word) {
            if (beta.find(c) == beta.end()) {
                f = false;
                break;
            }
        }
        if (f) std::cout << word << std::endl;
        --N;
    }
    return 0;
}
