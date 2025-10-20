#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>


int _calc_product(const std::vector<int>& _first, const std::vector<int>& _second) {
    int result = 0;
    for (size_t _i = 0; _i < _first.size(); ++_i) result += _first[_i] * _second[_i];
    return result;
}

void _closet_words(const std::vector<std::string>& _words, const std::vector<std::vector<int>>& _w_vectors) {
    int _a = _w_vectors.size();
    const auto &_main_vec = _w_vectors[0];
    int _max_dot = std::numeric_limits<int>::min();
    std::vector<int> _dots(_a, 0);
    for (int _i = 1; _i < _a; ++_i) {
        _dots[_i] = _calc_product(_main_vec, _w_vectors[_i]);
        if (_dots[_i] > _max_dot) _max_dot = _dots[_i];
    }
    for (int _i = 1; _i < _a; ++_i) if (_dots[_i] == _max_dot) std::cout << _words[_i] << '\n';
}




int main() {
    int M, N;
    std::cin >> M >> N;
    std::vector<std::string> words(M);
    std::vector<std::vector<int>> w_vectors(M, std::vector<int>(N));
    for (int i = 0; i < M; ++i) {
        std::cin >> words[i];
        for (int j = 0; j < N; ++j) std::cin >> w_vectors[i][j];
    }
    _closet_words(words, w_vectors);
    return 0;
}
