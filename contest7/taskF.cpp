#include <iostream>
#include <string>
#include <stack>


int main() {
    std::string s;
    std::cin >> s;
    std::stack<char> st;
    bool f = false;
    for (char c: s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                std::cout << "no";
                f = true;
                break;
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                std::cout << "no";
                f = true;
                break;
            }
        }
    }
    if ((!f) && (st.empty())) std::cout << "yes";
    else if (!f) std::cout << "no";
    return 0;
}
