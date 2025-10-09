#include <iostream>
#include <string>

std::string extractDigits(std::string _stroka) {
    int _len = _stroka.length(), _curr_int;
    char _curr_char;
    for (int _i = 0; _i < _len; ++_i) {
        _curr_char = _stroka[_i];
        _curr_int = _curr_char;
        if (_curr_int < 48 || _curr_int > 57) {
            _stroka.erase(_i, 1);
            --_i;
            _len = _stroka.length();
        }
    }
    return _stroka;
}

int main() {
    std::string given;
    std::getline(std::cin, given);
    std::cout << extractDigits(given);
    return 0;
}