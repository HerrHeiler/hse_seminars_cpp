#include <iostream>
#include <set>


int main() {
    std::set<int> setik;
    int t;
    while (std::cin >> t) {
        if (setik.count(t)) std::cout << "YES" << '\n';
        else {
            std::cout << "NO" << '\n';
            setik.insert(t);
        }
    }
    return 0;
}
