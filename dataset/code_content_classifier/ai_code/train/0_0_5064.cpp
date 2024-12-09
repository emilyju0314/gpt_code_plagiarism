#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            for (int l = 0; l < i; l++) {
                if (sequence[l] < sequence[i]) {
                    dp[j][i] += dp[j - 1][l];
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[k][i];
    }

    cout << ans << endl;

    return 0;
}