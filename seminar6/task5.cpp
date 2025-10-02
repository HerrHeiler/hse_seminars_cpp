#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    std::cout << "Input: " << s << '\n';
    int l = s.length();
    if (s[0] == '-') --l;
    for (int i = 0; i < 0; ++i) {
        std::cout << "sifu";
    }
    std::cout << "Output: Number " << s << " has " << l << " digits";
    return 0;
}