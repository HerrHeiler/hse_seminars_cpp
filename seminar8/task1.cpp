#include <iostream>
#include <cstddef>
#include <concepts>
#include <type_traits>

template<class T> 
//requires(std::integral<T> || std::floating_point<T>)
T findMax(const T* a) {
    T maxi = a[0];
    for (int i = 1; i < a.length(); ++i) {
        if (a[i] > maxi) {
            maxi = a[i];
        }
    }
    return maxi;
}

int main() {
    int test[] = {1, 2, 3, 4, 3};
    //std::string test[] = {"ett", "f"};
    std::cout << findMax(test);
    return 0;
}