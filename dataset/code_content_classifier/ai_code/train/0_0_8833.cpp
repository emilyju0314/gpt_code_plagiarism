#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;

        for (int j = t-1; j > s; j--) {
            dp[j] = (dp[j] + dp[j-1]) % mod;
        }
    }

    cout << dp[n] << endl;

    return 0;
}