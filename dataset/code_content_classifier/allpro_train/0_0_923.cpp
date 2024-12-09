#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    for (int i = 2; i < n + 1; i++) {
        vector<bool> win(i, false);
        for (int j = 1; j <= i / 2; j++) {
            if (!win[i - j]) {
                win[j] = true;
            }
        }
        for (int j = 1; j < i; j++) {
            if (!win[j]) {
                dp[i] = max(dp[i], j);
            }
        }
    }

    if (dp[n] != -1) {
        cout << dp[n] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}