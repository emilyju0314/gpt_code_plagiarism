#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    string expression;
    cin >> expression;

    stack<char> st;
    int p, m;
    cin >> p >> m;

    int num_opened = 0;
    for (char c : expression) {
        if (c == '(') {
            num_opened++;
        } else if (c == ')') {
            num_opened--;
        } else if (c == '?') {
            if (p > 0 && num_opened % 2 == 0) {
                st.push('+');
                p--;
            } else if (m > 0 && num_opened % 2 == 1) {
                st.push('-');
                m--;
            }
        } else if (c >= '0' && c <= '9') {
            if (!st.empty() && st.top() == '+') {
                st.pop();
                st.push(c);
            } else if (!st.empty() && st.top() == '-') {
                st.pop();
                int num = st.top() - '0';
                st.pop();
                st.push(num - (c - '0') + '0');
            } else {
                st.push(c);
            }
        }
    }

    cout << st.top() << endl;

    return 0;
}