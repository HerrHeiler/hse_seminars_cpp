#include <iostream>
#include <string>
#include <cmath>

int main() {
    int n, cnt = 1, temp, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0, a10 = 0, a11 = 0, a12 = 0, a13 = 0, a14 = 0, a15 = 0;
    std::string temp_bin = "", res_bin = "";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        temp_bin = std::to_string(temp);
        while (temp_bin.length() != 15) {
            temp_bin = '0' + temp_bin;
        }
        a1 = (a1 + temp_bin[0])%3;
        a2 = (a2 + temp_bin[1])%3;
        a3 = (a3 + temp_bin[2])%3;
        a4 = (a4 + temp_bin[3])%3;
        a5 = (a5 + temp_bin[4])%3;
        a6 = (a6 + temp_bin[5])%3;
        a7 = (a7 + temp_bin[6])%3;
        a8 = (a8 + temp_bin[7])%3;
        a9 = (a9 + temp_bin[8])%3;
        a10 = (a10 + temp_bin[9])%3;
        a11 = (a11 + temp_bin[10])%3;
        a12 = (a12 + temp_bin[11])%3;
        a13 = (a13 + temp_bin[12])%3;
        a14 = (a14 + temp_bin[13])%3;
        a15 = (a15 + temp_bin[14])%3;
    }
    unsigned long long res = a1*100000000000000 + a2*10000000000000 + a3*1000000000000 + a4*100000000000 + a5*10000000000 + a6*1000000000 + a7*100000000 + a8*10000000 + a9*1000000 + a10*100000 + a11*10000 + a12*1000 + a13*100 + a14*10 + a15;
    if (a1 == 2 || a2 == 2 || a3 == 2 || a4 == 2 || a5 == 2 || a6 == 2 || a7 == 2 || a8 == 2 || a9 == 2 || a10 == 2 || a11 == 2 || a12 == 2 || a13 == 2 || a14 == 2 || a15 == 2) {
        res /= 2;
        cnt = 2;
    }
    std::cout << res << std::endl;
    res_bin = std::to_string(res);
    int dec_res = 0, base = 1;
    while (res) {
        int last_dig = res % 10;
        res /= 10;
        dec_res += last_dig * base;
        base *= 2;
    }
    std::cout << dec_res << " " << cnt;
    return 0;
}