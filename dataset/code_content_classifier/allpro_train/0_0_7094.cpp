#include <iostream>
#include <stack>

int main() {
    int n;
    std::cin >> n;

    std::stack<std::string> st;
    for(int i = 0; i < n; i++) {
        std::string p;
        int x;
        std::cin >> p >> x;

        st.push(std::to_string(x) + p);
        while(st.size() >= 2) {
            std::string s2 = st.top();
            st.pop();
            std::string s1 = st.top();
            st.pop();

            if(s1[1] == '(' && s2[1] == ')') {
                st.push("(" + s1 + s2 + ")");
            } else {
                st.push(s1 + s2);
            }
        }
    }

    std::string final_str = st.top();
    if(final_str[0] == '(' && final_str[final_str.size()-1] == ')') {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}