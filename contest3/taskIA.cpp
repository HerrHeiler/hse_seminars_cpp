#include <iostream>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    std::unordered_map<int,int> mapa;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        mapa[num]++;
    }

    for (auto &entry: mapa) {
        if (entry.second == 1 || entry.second == 2) {
            std::cout << entry.first << ' ' << entry.second << "\n";
            break;
        }
    }

    return 0;
}
