#include <iostream>
#include <vector>
//#include <я устал, босс>
#include <string>
#include <algorithm>


struct Word {
    std::string text;
    std::vector<long long> description;
};

template <typename T>
long long dot_product(const T& first, const T& second) {
    long long result = 0;
    for (size_t i = 0; i < first.size(); ++i) result += first[i]*second[i];
    return result;
}

int main() {
    size_t m, n;
    std::cin >> m >> n;
    std::vector<Word> words;
    for (size_t i = 0; i < m ; ++i) {
        Word t;
        std::cin >> t.text;
        t.description.resize(n);
        for (size_t j = 0; j < n; ++j) std::cin >> t.description[j];
        words.push_back(std::move(t));
    }
    const std::vector<long long>& first = words[0].description;
    long long maxi = dot_product(first, words[1].description);
    std::vector<std::string> answer;
    answer.push_back(words[1].text);
    for (size_t i = 2; i < words.size(); ++i) {
        const std::vector<long long>& t = words[i].description;
        long long temp = dot_product(first, t);
        if (temp > maxi) {
            maxi = temp;
            answer.clear();
            answer.push_back(words[i].text);
            //std::cout << "im here 43 line >\n";
        } else if (temp == maxi) {
            answer.push_back(words[i].text);
            //std::cout << "im here ==\n";
        }
    }
    for (const auto& e : answer) std::cout << e << std::endl;
    return 0;
}