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

int main() {
    //std::string stroka;
    //std::getline(std::cin, stroka);
    //std::cout << stroka << std::endl;
    //std::cout << stroka.length() << std::endl;
    //stroka.erase(4, 1);
    //std::cout << delete_spaces(stroka);
    std::string _sus = "12345";
    char pld = _sus[_sus.length() - 2] + 1;
    int pp = pld - '0';
    std::cout << pld << ' ' << pp << '\n';
    int ld = _sus[_sus.length() - 1] - '0';
    std::cout << ld;
    return 0;
}