#include <iostream>

void Sort(int* begin, int* end) {
    int n = end - begin + 1;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (begin[j] > begin[j+1]) std::swap(begin[j], begin[j+1]);
        }
    }
}

int main() {
    int a;
    std::cin >> a;
    int* s = new int[a];
    for (int k = 0; k < a; ++k) std::cin >> s[k];
    Sort(s, s+a-1);
    for (int j = 0; j < a; ++j) std::cout << s[j] << ' ';
    //for (int i = 0; i < a; ++i) delete[] s[i];
    return 0;
}
