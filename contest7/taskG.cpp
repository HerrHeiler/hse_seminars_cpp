#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>


bool matches(const std::string& plate, const std::string& witness) {
    std::unordered_set<char> plateChars(plate.begin(), plate.end());
    for (char c : witness) {
        if (plateChars.find(c) == plateChars.end())
            return false;
    }
    return true;
}

int main() {
    int a, b;
    std::cin >> a;
    std::vector<std::string> wits(a);
    for (int i = 0; i < a; ++i) {
        std::string temp;
        std::cin >> temp;
        wits[i] = temp;
    }
    std::cin >> b;
    std::vector<std::string> pls(b);
    for (int i = 0; i < b; ++i)
        std::cin >> pls[i];

    std::vector<int> mats(b, 0);
    int maxi = 0;
    for (int i = 0; i < b; ++i) {
        for (const std::string& t : wits) {
            if (matches(pls[i], t)) ++mats[i];
        }
        maxi = std::max(maxi, mats[i]);
    }
    //std::cout << "ans" << '\n' << '\n' << '\n';
    for (int i = 0; i < b; ++i) if (mats[i] == maxi) std::cout << pls[i] << '\n';
    return 0;
}
