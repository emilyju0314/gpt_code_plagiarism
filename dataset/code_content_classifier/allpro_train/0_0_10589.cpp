#include <iostream>
#include <vector>
using namespace std;
#define MOD 998244353

int main() {
    int n;
    cin >> n;

    vector<int> c(26);
    for(int i = 0; i < 26; i++) {
        cin >> c[i];
    }

    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(30, vector<long long>(30, 0)));
    dp[0][27][27] = 1;

    for(int i = 0; i < n; i++) {
        for(int l1 = 0; l1 < 27; l1++) {
            for(int l2 = 0; l2 < 27; l2++) {
                if(dp[i][l1][l2] == 0) continue;
                for(int j = 0; j < 26; j++) {
                    if(c[j] < i+1) {
                        dp[i+1][l2][j] = (dp[i+1][l2][j] + dp[i][l1][l2]) % MOD;
                    }
                }
            }
        }
    }

    long long ans = 0;
    for(int l1 = 0; l1 < 27; l1++) {
        for(int l2 = 0; l2 < 27; l2++) {
            ans = (ans + dp[n][l1][l2]) % MOD;
        }
    }
    cout << ans << endl;

    return 0;
}