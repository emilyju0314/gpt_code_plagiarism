#include <iostream>
#include <stack>
#include <string>

bool canDetermineSpecies(int n, std::string formula) {
    std::stack<char> st;
    for (char c : formula) {
        if (c == ')') {
            std::string subExp;
            while (st.top() != '(') {
                subExp += st.top();
                st.pop();
            }
            st.pop(); // pop '('

            if (subExp.find('?') == std::string::npos || subExp.find('0') == std::string::npos || subExp.find('1') == std::string::npos) {
                return false;
            }
            st.push('1'); // result of subexpression
        } else {
            st.push(c);
        }
    }

    return true;
}

int main() {
    int n;
    std::string formula;

    std::cin >> n;
    std::cin >> formula;

    if (canDetermineSpecies(n, formula)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}