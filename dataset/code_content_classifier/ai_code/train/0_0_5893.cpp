#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + a);

        for (int j = i - 2; j >= 0; j--) {
            string sub = s.substr(j, i - j);
            int cost = b;
            if (s.substr(0, j).find(sub) != string::npos) {
                cost = 0;
            }
            dp[i] = min(dp[i], dp[j] + cost);
        }
    }

    cout << dp[n] << endl;

    return 0;
}