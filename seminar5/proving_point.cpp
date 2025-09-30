#include <iostream>

int main() {
    int a = 10, b = 16;
    int* const pA = &a;
    a = 5;
    *pA = 15;
    //pA = &b;
    return 0;
}