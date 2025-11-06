#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> words;
    std::string temp;
    while (std::cin >> temp) words.push_back(temp);
    std::vector<int> common(26, 1001);
    for (const std::string& w: words) {
        std::vector<int> freq(26);
        for (char c: w) freq[c - 'a']++;
        for (int i = 0; i < 26; ++i) common[i] = std::min(common[i], freq[i]);
    }
    for (int i = 0; i < 26; ++i) if (common[i] > 0) std::cout << (char)('a' + i);
    std::cout << '\n';
    return 0;
}
