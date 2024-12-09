#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    vector<int> dp(n+1, 0);
    stack<int> st;

    for (int i = 1; i <= n; i++) {
        if (s[i-1] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                dp[i] = dp[i-1] + 2;
                int prev = st.top();
                if (prev > 1) {
                    dp[i] += dp[prev-1];
                }
                st.pop();
            }
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int li, ri;
        cin >> li >> ri;
        cout << dp[ri] - dp[li-1] << endl;
    }

    return 0;
}