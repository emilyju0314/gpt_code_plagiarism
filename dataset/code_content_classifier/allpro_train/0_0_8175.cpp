#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> dp(n);
    
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                int idx = st.top();
                st.pop();
                dp[i] = dp[max(0, idx - 1)] + i - idx + 1;
            }
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int li, ri;
        cin >> li >> ri;
        cout << dp[ri - 1] - (li > 1 ? dp[li - 2] : 0) << endl;
    }

    return 0;
}