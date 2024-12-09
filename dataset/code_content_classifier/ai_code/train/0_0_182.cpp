#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        vector<int> buttonCount(26, 0);

        for (int i = 0; i < m; i++) {
            int p;
            cin >> p;
            buttonCount[s[p - 1] - 'a']++;
        }

        vector<int> dp(n, 0);
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1 - buttonCount[s[i] - 'a'];
        }

        for (int i = 0; i < n; i++) {
            buttonCount[s[i] - 'a'] += dp[i];
        }

        for (int i = 0; i < 26; i++) {
            cout << buttonCount[i] << " ";
        }
        cout << endl;
    }

    return 0;
}