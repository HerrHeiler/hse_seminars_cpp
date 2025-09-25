#include <iostream>

int main() {
    std::string word, answer = "";
    std::cin >> word;
    answer += word[0];
    for (int i = 1; i < word.length(); ++i) {
        char sym = word[i];
        std::string temp = "";
        if (sym == 'a' || sym == 'e' || sym == 'h' || sym == 'i' || sym == 'o' || sym == 'u' || sym == 'w' || sym == 'y') continue;
        if (sym == 'b' || sym == 'f' || sym == 'p' || sym == 'v') temp = "1";
        if (sym == 'c' || sym == 'g' || sym == 'j' || sym == 'k' || sym == 'q' || sym == 's' || sym == 'x' || sym == 'z') temp = "2";
        if (sym == 'd' || sym == 't') temp = "3";
        if (sym == 'l') temp = "4";
        if (sym == 'm' || sym == 'n') temp = "5";
        if (sym == 'r') temp = "6";
        if (temp[0] != answer[answer.length()-1]) answer += temp;
        if (answer.length() == 4) break;
    }
    while (answer.length() != 4) answer += '0';
    std::cout << answer;
    return 0;
}