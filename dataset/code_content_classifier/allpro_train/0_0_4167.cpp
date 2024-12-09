#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minChanges(string s, int k) {
    vector<vector<int>> dp(k, vector<int>(3, 0));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 0) {
                dp[i][j] = (s[i] != "RGB"[j]);
            } else {
                dp[i][j] = dp[i-1][j] + (s[i % k] != "RGB"[j]);
            }
        }
    }

    int minChanges = k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 3; j++) {
            minChanges = min(minChanges, dp[k-1][j] - dp[i][j]);
        }
    }

    return minChanges;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        cout << minChanges(s, k) << endl;
    }

    return 0;
}