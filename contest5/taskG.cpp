#include <iostream>

void solution() {
    int _n, _m, _temp;
    std::cin >> _n >> _m;
    int** _s = new int*[_n];
    for (int _i = 0; _i < _n; ++_i) _s[_i] = new int[_m]();
    for (int _i = 0; _i < _n; ++_i) {
        for (int _j = 0; _j < _m; ++_j) {
            std::cin >> _temp;
            _s[_i][_j] = _temp;
        }
    }
    int _pom1, _pom2;
    std::cin >> _pom1 >> _pom2;
    for (int _i = 0; _i < _n; ++_i) {
        for (int _j = 0; _j < _m; ++_j) {
            if (_j == _pom1) std::cout << _s[_i][_pom2];
            else if (_j == _pom2) std::cout << _s[_i][_pom1];
            else std::cout << _s[_i][_j];
            if (_j == (_m - 1)) std::cout << '\n';
            else std::cout << ' ';
        }
    }
}

int main() {
    solution();
    return 0;
}