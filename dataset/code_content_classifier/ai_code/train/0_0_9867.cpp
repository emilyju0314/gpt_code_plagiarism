#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

const int MOD = 2011;
const int INV_2011 = 1149;

int evaluate(const vector<string>& expression) {
    stack<int> st;
    for (int i = 0; i < expression[0].size(); i++) {
        char c = expression[1][i];
        if (c == '.') continue;
        if (isdigit(c)) st.push(c - '0');
        else if (c == '(') st.push(-1);
        else if (c == '+') st.push(-2);
        else if (c == '-') st.push(-3);
        else if (c == '*') {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push((1LL * a * b) % MOD);
        }
        else if (c == ')') {
            int num = 0;
            while (st.top() != -1) {
                num = (10 * num + st.top()) % MOD;
                st.pop();
            }
            st.pop();
            st.push(num);
        }
    }
    return st.top();
}

int main() {
    int n;
    while (cin >> n && n) {
        vector<string> expression(n);
        cin.ignore();
        for (int i = 0; i < n; i++) {
            getline(cin, expression[i]);
        }

        int result = evaluate(expression);
        cout << result << endl;
    }

    return 0;
}