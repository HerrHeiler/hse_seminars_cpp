#include <iostream>

int main() {
    int N, M, W;
    const int size = 32;
    std::cin >> N >> M >> W;
    int mine[size][size] = {0};

    for (int l = 0; l < W; ++l) {
        int t1, t2;
        std::cin >> t1 >> t2;
        mine[t1 - 1][t2 - 1] = 1;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (mine[i][j] == 1) {
                std::cout << '*';
            } else {
                int t = 0;
                if (i != 0) t += mine[i - 1][j];
                if (j != 0) t += mine[i][j - 1];
                if (i != 0 && j != 0) t += mine[i - 1][j - 1];
                if (i < N - 1) t += mine[i + 1][j];
                if (j < M - 1) t += mine[i][j + 1];
                if (i < N - 1 && j < M - 1) t += mine[i + 1][j + 1];
                if (i != 0 && j < M - 1) t += mine[i - 1][j + 1];
                if (i < N - 1 && j != 0) t += mine[i + 1][j - 1];
                std::cout << t;
            }
            if (j != M - 1) std::cout << ' ';
            else std::cout << ' ' << '\n';
        }
    }
    return 0;
}