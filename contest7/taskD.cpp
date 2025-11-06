#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> dirs;
    std::string path;
    while (std::getline(std::cin, path)) {
        if (path.empty()) continue;
        dirs.insert("/");
        for (int i = 1; i < path.size(); ++i) {
            if (path[i] == '/') {
                dirs.insert(path.substr(0, (i + 1)));
            }
        }
    }
    for (std::set<std::string>::iterator it = dirs.begin(); it != dirs.end(); ++it) {
        std::cout << *it << '\n';
        // control d
    }
    return 0;
}
