#include <iostream>
#include <cstddef>
#include <concepts>
#include <type_traits>

template<class T> 
concept Member = std::integral<T> || std::floating_point<T>;
template<Member T>
T calculateAverage(const std::vector<T> &a) {
    T sum = 0;
    for(T i = a.begin(); i < a.size(); ++i) {
        sum += 1;
    }
    return sum / a.size();
}

int main() {
    //std::vector<long long
    return 0;
}