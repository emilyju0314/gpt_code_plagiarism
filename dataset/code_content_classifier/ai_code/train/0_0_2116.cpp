#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> dp(n+1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i-1] + 2 - dp[p[i-1]-1] + MOD) % MOD; 
    }

    cout << dp[n] << endl;

    return 0;
}