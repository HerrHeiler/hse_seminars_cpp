#include <iostream>

void solution() {
    int _n, _m, _temp;
    std::cin >> _n >> _m;
    int** _s = new int*[_m];
    for (int _i = 0; _i < _m; ++_i) _s[_i] = new int[_n]();
    for (int _i = 0; _i < _n; ++_i) {
        for (int _j = 0; _j < _m; ++_j) {
            std::cin >> _temp;
            _s[_j][_i] = _temp;
        }
    }
    for (int _i = 0; _i < _m; ++_i) {
        for (int _j = 0; _j < _n; ++_j) {
            if(_j != _n - 1) std::cout << _s[_i][_j] << ' ';
            else std::cout << _s[_i][_j] << '\n';
        }
    }
}

int main() {
    solution();
    return 0;
}