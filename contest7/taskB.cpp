#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int n, t;
    std::cin >> n;
    std::map<int, std::set<std::string>> data;
    std::string temp;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp >> t;
        data[t].insert(temp);
    }
    for (std::map<int, std::set<std::string>>::iterator it = data.begin(); it != data.end(); ++it) {
        std::cout << it->first;
        for (std::set<std::string>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            std::cout << ' ' << *it2;
        }
        std::cout << '\n';
    }
    return 0;
}
