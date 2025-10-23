#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<std::vector<int>> _gen_mat(int _n, int _m) {
    std::vector<std::vector<int>> _mat(_n, std::vector<int>(_m));
    for (int _i = 0; _i < _mat.size(); ++_i) {
        for (int _j = 0; _j < _mat[_i].size(); ++_j) {
            _mat[_i][_j] = rand() % 101 - 50;
        }
    }
    return _mat;
}


void replace_negatives_with_squares (std::vector<std::vector<int>>& _mat) {
    for (int _i = 0; _i < _mat.size(); ++_i) {
        for (int _j = 0; _j < _mat[_i].size(); ++_j) {
            if (_mat[_i][_j] < 0) _mat[_i][_j] = _mat[_i][_j]*_mat[_i][_j];
        }
    }
}

template <typename Matrix>
void _print_mat(const Matrix& _mat) {
    for (int _i = 0; _i < _mat.size(); ++_i) {
        for (int _j = 0; _j < _mat[_i].size(); ++_j) {
            std::cout << _mat[_i][_j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<std::vector<int>> mat = _gen_mat(4, 5);
    _print_mat(mat);
    replace_negatives_with_squares(mat);
    _print_mat(mat);
    return 0;
}