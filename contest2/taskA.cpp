#include <iostream>

int main() {
    char input_char;
    std::cin >> input_char;
    int char_code = (int)input_char;
    if (char_code >= 65 && char_code <= 90 || char_code >= 97 && char_code <= 122) {
        std::cout << "correct";
    } else {
        std::cout << "incorrect";
    }
    return 0;
}