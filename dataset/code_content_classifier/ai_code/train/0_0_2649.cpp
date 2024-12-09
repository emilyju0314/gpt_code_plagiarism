#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    vector<vector<int>> dp(n, vector<int>(9, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = dp[i][j-1];
        }
        dp[i][cards[i]]++;
    }

    int max_len = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int cnt = 0;
            for (int k = 1; k <= 8; k++) {
                int freq = dp[j][k] - (i > 0 ? dp[i-1][k] : 0);
                cnt = max(cnt, freq);
            }
            max_len = max(max_len, cnt + min(i, n - j - 1));
        }
    }

    cout << max_len << endl;

    return 0;
}