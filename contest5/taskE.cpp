#include <iostream>

std::string find_largest() {
    std::string _answer;
    int _n, _m, _max_n, _max_m, _max_va = 0, _temp;
    std::cin >> _n >> _m;
    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < _m; ++j) {
            std::cin >> _temp;
            if (_temp > _max_va) {
                _max_n = i;
                _max_m = j;
                _max_va = _temp;
            }
        }
    }
    std::cout << _max_n << ' ' << _max_m;
    return _answer;
}

int main() {
    find_largest();
    return 0;
}