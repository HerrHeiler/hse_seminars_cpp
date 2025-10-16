#include <iostream>
#include <string>

std::string plusodin(std::string _sus) {
    int _dig = 1;
    for (int i = _sus.length() - 1; ((i >= 0) && (_dig)); --i) {
        int _curr_dig = _sus[i] - '0' + _dig;
        _dig = _curr_dig / 10;
        _curr_dig %= 10;
        _sus[i] = _curr_dig + '0';
    }
    if (_dig) _sus.insert(_sus.begin(), '1');
    return _sus;
}

int main() {
    std::string given;
    std::cin >> given;
    std::cout << plusodin(given);
    return 0;
}
