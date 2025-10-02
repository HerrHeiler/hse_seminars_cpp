#include <iostream>

int main() {
    int N, M, W;
    int mine [N][M];
    for (int l = 0; l < W; ++l) {
        int t1, t2;
        std::cin >> t1 >> t2;
        mine[t1 - 1][t2 - 1] = 1;
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            //if ()
        }
    }
    return 0;
}