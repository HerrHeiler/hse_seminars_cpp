#include <iostream>
#include <map>
#include <vector>
#include <string>

int main() {
    int a, t;
    std::cin >> a;
    std::map<std::string, std::vector<int>> mapa;
    for (int i = 0; i < a; ++i) {
        int b;
        std::cin >> b;
        for (int j = 0; j < b; ++j) {
            std::string temp;
            std::cin >> temp >> t;
            if (mapa[temp].empty())
                mapa[temp] = std::vector<int>(a, 0);
            mapa[temp][i] = t;
        }
    }
    for (std::map<std::string, std::vector<int>>::iterator it = mapa.begin(); it != mapa.end(); ++it) {
        std::cout << it->first;
        for (int i = 0; i < (it->second).size(); ++i) {
            std::cout << '\t' << it->second[i];
        }
        std::cout << '\n';
    }
    return 0;
}
