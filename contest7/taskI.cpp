// pre last task yeaaaahhhhhh lets go
// no i hate you vovochka   >://
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>


int main() {
    std::map<char, int> freq;
    std::string temp;
    while (std::getline(std::cin, temp)) for (char c: temp) if (c != ' ' && c != '\n') freq[c]++;
    std::vector<std::pair<char,int>> cs(freq.begin(), freq.end());
    std::sort(cs.begin(), cs.end());
    int maxi = 0;
    for (auto& p: cs) maxi = std::max(maxi, p.second);
    for (int row = maxi; row >= 1; --row) {
        for (auto& p: cs) {
            if (p.second >= row) std::cout << '#';
            else std::cout << ' ';
        }
        std::cout << '\n';
    }
    for (auto& p: cs) std::cout << p.first;
    return 0;
}
