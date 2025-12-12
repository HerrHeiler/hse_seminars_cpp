#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

enum Category {E = 0, D = 1, C = 2, B = 3, A = 4, S = 5};

struct Stats {
    
};

class Titanic {
public:
    std::string full_name;
    uint16_t age;
    Category cat;
    bool is_alive;
//smth
};

std::vector<Titanic> parsingCSV(const std::string& filename) {
    std::vector<Titanic> passengers;
    std::ifstream file(filename);
    std::string line;
    
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> data;
        while (std::getline(ss, token, ',')) data.push_back(token);
        Titanic t;
        t.full_name = data[0];
        t.age = std::stoi(data[1]);
        t.cat = static_cast<Category>(std::stoi(data[2]));
        t.is_alive = std::stoi(data[3]);
        passengers.push_back(t);
    }
    return passengers;
}

int main() {

    return 0;
}