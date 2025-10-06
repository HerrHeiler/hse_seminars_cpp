#include <iostream>

bool correct_password(std::string _password) {
    bool _ll = false, _sl = false, _nums = false, _os = false;
    if (_password.length() < 8 || _password.length() > 14) return false;
    for (int _i = 0; _i < _password.length(); ++_i) {
        char _sym = _password[_i];
        int _sym_code = _sym;
        if (_sym_code < 33 || _sym_code > 127) return false;
        if (_sym_code <= 47 || (_sym_code >= 58 && _sym_code <= 64) || (_sym_code >= 91 && _sym_code <= 96)) _os = true;
        else if (_sym_code <= 57) _nums = true;
        else if (_sym_code <= 90) _ll = true;
        else _sl = true;
    }
    if (_ll + _sl + _nums + _os < 3) return false;
    return true;
}


int main() {
    std::string password;
    std::cin >> password;
    if (correct_password(password)) std::cout << "YES";
    else std::cout << "NO";
    return 0;
}