#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> weights(n);
    int totalWeight = 0;
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
        totalWeight += weights[i];
    }

    if(n == 1) {
        if(weights[0] > k) {
            cout << -1 << endl;
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
            cout << 1 << endl;
        }
        return 0;
    }

    if(totalWeight % k != 0 || count(weights.begin(), weights.end(), 100) > totalWeight / k || count(weights.begin(), weights.end(), 100) % 2 != 0) {
        cout << -1 << endl;
        cout << 0 << endl;
        return 0;
    }
    
    int dp[51][5001] = {0};
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if(j - weights[i-1] >= 0) {
                dp[i][j] += dp[i-1][j - weights[i-1]];
            }
            dp[i][j] %= 1000000007;
        }
    }

    int minRides = (totalWeight / k);
    cout << minRides << endl;
    cout << dp[n][k] << endl;

    return 0;
}