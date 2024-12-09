#include <iostream>
#include <vector>
#include <cstring>

#define mod 1000000007

using namespace std;

vector<int> g[1000005];
int dp[1000005], f1, f2, k, n, m;

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        cin >> f1 >> f2;
        if (f2 - f1 - 1 > k) {
            cout << 0;
            return 0;
        }

        if (f2 - f1 == k + 1) ++dp[f1];
    }

    dp[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        dp[i] += dp[i-1] + dp[i];
        dp[i] %= mod;
    }

    cout << dp[n];
    return 0;
}