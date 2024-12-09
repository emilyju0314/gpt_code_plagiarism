#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<int> dp(n, 0);

    int cnt = 0;
    int max_len = 0;
    int max_idx = -1;

    for (int i = 1; i < n; i++) {
        if (s[i] == ']') {
            if (s[i - 1] == '[') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (s[i - 1] == '(' && i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '[') {
                dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0);
            }
        }

        if (dp[i] > max_len) {
            max_len = dp[i];
            max_idx = i;
        }
    }

    cout << max_len / 2 << endl;

    if (max_idx != -1) {
        for (int i = max_idx - max_len + 1; i <= max_idx; i++) {
            cout << s[i];
        }
    }

    return 0;
}