#include <iostream>
#include <vector>

template <class T , class F>
void map2d (std::vector<std::vector<T>>& a, F f) {
    for (int _i = 0; _i < a.size(); ++_i) {
        for (int _j = 0; _j < a[_i].size(); ++_j) {
            a[_i][_j] = f(a[_i][_j]);
        }
    }
}
// template <class T, class F>
// void map2d(std::vector<std::vector<T>>& a, F f) {
//     for (auto& row : a) {
//         for (auto& elem : row) {
//             elem = f(elem);
//         }
//     }



template<class T, class Pred>
std::size_t count_if2d(const std::vector<std::vector<T>>& a, Pred p) {
    std::size_t cnt = 0;
    for (int _i = 0; _i < a.size(); ++_i) {
        for (int _j = 0; _j < a[_i].size(); ++_j) {
            if (p(a[_i][_j])) ++cnt;
        }
    }
    return cnt;
}


template<class T, class U, class Op>
U reduce2d(const std::vector<std::vector<T>>& a, U init, Op op) {
    U result = init;
    for (int _i = 0; _i < a.size(); ++_i) {
        for (int _j = 0; _j < a[_i].size(); ++_j) {
            result = op(a[_i][_j], result);
        }
    }
    return result;
}

void _print(const std::vector<std::vector<int>>& _mat) {
    for (int _i = 0; _i < _mat.size(); ++_i) {
        for (int _j = 0; _j < _mat[_i].size(); ++_j) {
            std::cout << _mat[_i][_j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> mat(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int t;
            std::cin >> t;
            mat[i][j] = t;
        }
    }
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::string temp_n, temp_a;
        int temp_v;
        std::cin >> temp_n >> temp_a;
        if (temp_n == "MAP") {
            std::cin >> temp_v;
            if (temp_a == "ADD") {
                _print(mat);
                std::cout << '\n' << "ADD" << '\n';
                map2d(mat, [temp_v](int x) {return temp_v + x;});
                _print(mat);
            } else {
                _print(mat);
                std::cout << '\n' << "MUL" << '\n';
                map2d(mat, [temp_v](int x) {return temp_v * x;});
                _print(mat);
            }
        } else if (temp_n == "FILTER") {
            std::cin >> temp_v;
            if (temp_a == "GT") {
                // _print(mat);
                std::cout << '\n' << "GT" << '\n';
                std::cout << count_if2d(mat, [temp_v](int x) {return temp_v < x;}) << '\n';
                // _print(mat);
            } else if (temp_a == "GE")  {
                // _print(mat);
                std::cout << '\n' << "GE" << '\n';
                std::cout << count_if2d(mat, [temp_v](int x) {return temp_v <= x;}) << '\n';
                // _print(mat);
            } else {
                //_print(mat);
                std::cout << '\n' << "EQ" << '\n';
                std::cout << count_if2d(mat, [temp_v](int x) {return temp_v == x;}) << '\n';
                //_print(mat);
            }
        } else {
            if (temp_a == "SUM") {
                //_print(mat);
                std::cout << '\n' << "SUM" << '\n';
                std::cout << reduce2d(mat, 0, [](int x, int y) {return y + x;}) << '\n';
                //_print(mat);
            } else if (temp_a == "MAX") {
                //_print(mat);
                std::cout << '\n' << "MAX" << '\n';
                std::cout << reduce2d(mat, mat[0][0], [](int x, int y) {return y > x ?  y : x;}) << '\n';
                //_print(mat);
            } else {
                //_print(mat);
                std::cout << '\n' << "MIN" << '\n';
                std::cout << reduce2d(mat, mat[0][0], [](int x, int y) {return y < x ?  y : x;}) << '\n';
                //_print(mat);
            }
        }
    }

    return 0;
}

// int max_val = reduce2d(matrix, std::numeric_limits<int>::min(), 
// [](int acc, int val) { return std::max(acc, val); });
