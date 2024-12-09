#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string s, t, u;
    std::cin >> s;

    std::stack<char> st;

    for (char c : s) {
        st.push(c);
    }

    while (!st.empty()) {
        if (t.empty() || st.top() <= t.front()) {
            t = st.top() + t;
        } else {
            u += st.top();
        }
        st.pop();
    }

    std::cout << u << std::endl;

    return 0;
}