#include <iostream>
#include <deque>
#include <list>
#include <chrono>
#include <vector>
#include <iomanip>


template<typename Func>
double measureTime(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> elapsed = stop-start;
    return elapsed.count();
}

template<typename Container>
double addToVectorB(int size) {
    return measureTime([size]() {
        Container container;
        for (int i=0;i<size;i++) {
            container.insert(container.begin(),i);
        }
    });
}
int main() {
    std::cout<<addToVectorB<std::vector<int>>(100000) << "\n";
    std::cout<<addToVectorB<std::deque<int>>(100000) << "\n";
    std::cout<<addToVectorB<std::list<int>>(100000) << "\n";
}
