#include <iostream>
#include <string>

std::string delete_spaces(std::string _stroka) {
    int _len = _stroka.length(), _curr_int;
    char _curr_char;
    for (int _i = 0; _i < _len; ++_i) {
        _curr_char = _stroka[_i];
        _curr_int = _curr_char;
        if (_curr_int ==  32) {
            _stroka.erase(_i, 1);
            --_i;
            _len = _stroka.length();
        }
    }
    return _stroka;
}

bool is_palindrome(std::string _stroka) {
    _stroka = delete_spaces(_stroka);
    char _curr_char, _other_char;
    int _curr_int, _other_int, _len = _stroka.length();
    for (int _i = 0; _i < _len; ++_i) {
        _curr_char = _stroka[_i];
        _other_char = _stroka[_len - _i - 1];
        _curr_int = _curr_char;
        _other_int = _other_char;
        if (_curr_int != _other_int) return false;
    }
    return true;
}

int main() {
    std::string given;
    std::getline(std::cin, given);
    if (is_palindrome(given)) std::cout << "yes";
    else std::cout << "no";
    return 0;
}