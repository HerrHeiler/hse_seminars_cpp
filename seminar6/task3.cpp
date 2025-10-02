#include <iostream>

int main() {
    std::string s, new_s = "";
    std::cin >> s;
    std::cout << "Original: " << s << ", Reversed: ";
    int l = s.length();
    bool f = true;
    for (int i = 0; i < l; ++i) {
        if (s[i] != s[l-i-1]) f = false;
        new_s += s[l-i-1];
    }
    std::cout << new_s << " - ";
    if (f) std::cout << "Palindrome!";
    else std::cout << "Not a palindrome!";
    return 0;
}