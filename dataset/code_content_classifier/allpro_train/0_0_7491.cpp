#include <iostream>
#include <stack>
#include <string>

int main() {
    int n, m, p;
    std::cin >> n >> m >> p;
    
    std::string brackets;
    std::cin >> brackets;
    
    std::string operations;
    std::cin >> operations;
    
    std::stack<int> st;
    std::stack<int> paired;
    
    int cursor = p - 1;
    for (int i = 0; i < n; i++) {
        if (brackets[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                paired.push(st.top());
                paired.push(i);
                st.pop();
            }
        }
    }
    
    for (char op : operations) {
        if (op == 'L') {
            if (cursor > 0) {
                cursor--;
            }
        } else if (op == 'R') {
            if (cursor < n - 1) {
                cursor++;
            }
        } else if (op == 'D') {
            int left = std::min(cursor, paired.top());
            int right = std::max(cursor, paired.top());
            cursor = paired.top();
            
            while (!paired.empty()) {
                paired.pop();
            }
            
            brackets.erase(left, right - left + 1);
            n -= (right - left + 1);
            
            for (int i = 0; i < n; i++) {
                if (brackets[i] == '(') {
                    st.push(i);
                } else {
                    if (!st.empty()) {
                        paired.push(st.top());
                        paired.push(i);
                        st.pop();
                    }
                }
            }
        }
    }
    
    std::cout << brackets << std::endl;
    
    return 0;
}