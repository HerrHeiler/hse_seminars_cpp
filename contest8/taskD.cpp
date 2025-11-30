#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <map>



struct Star {
    std::string name;
    uint64_t age;
};

std::vector<Star> CreateVector(std::istream &in) {
    size_t n;
    in >> n;
    std::vector<Star> stars(n);
    for (size_t i = 0; i < n; ++i) {
        in >> stars[i].name >> stars[i].age;
    }
    return stars;
}


std::string FindStar(const std::vector<Star>& stars) {
    std::string result;
    std::vector<uint64_t> ages;
    std::map<std::string, uint64_t> mapa;
    for (const auto& star : stars) {
        mapa[star.name] = std::max(mapa[star.name], star.age);
    }

    ages.reserve(mapa.size());
    for (const auto& [name, age] : mapa) {
        ages.push_back(age);
    }

    size_t median_index = ages.size() / 2;
    std::nth_element(ages.begin(), ages.begin() + median_index, ages.end());
    uint64_t mediana = ages[median_index];

    for (const auto& [name, age] : mapa) {
        if (age == mediana && (result.empty() || name < result)) {
            result = name;
        }
    }
    return result;
}

int main() {
    const auto stars = CreateVector(std::cin);
    std::cout << FindStar(stars) << "\n";
    return 0;
}