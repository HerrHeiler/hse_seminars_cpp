// 3 7 10 7 3 7 3 10
// 0011 0111 1010 0111 0011 0111 0011 1010
// 2386 % 3 => 2 0 2 0 => 10 x 2
#include <iostream>
#include <string>
#include <cmath>

int main() {
    int n, temp, s = 0;
    unsigned long long res = 0;
    std::string temp_bin = "";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        for (int j = 15; j >= 0; --j) {
            if (temp&(1<<j)) {
                s += std::pow(10, j);
            }
        }
    }
    temp_bin = std::to_string(s);
    //std::cout << temp_bin << std::endl;
    int len = temp_bin.length() - 1;
    int i = 0;
    bool f = false;
    while (i <= len) {
        int sym = temp_bin[i] - '0';
        //std::cout << sym << std::endl;
        sym %= 3;
        if (sym == 2) {
            f = true;
        }
        res += std::pow(10, len-i)*sym;
        ++i;
    }
    int cnt = 1;
    //std::cout << res << std::endl;
    if (f) {
        res /= 2;
        cnt = 2;
    }
    //std::cout << res << std::endl;
    unsigned long long dec_res = 0, base = 1;
    while (res) {
        int last_dig = res % 10;
        res /= 10;
        dec_res += last_dig * base;
        base *= 2;
    }
    std::cout << dec_res << " " << cnt;
    return 0;
}