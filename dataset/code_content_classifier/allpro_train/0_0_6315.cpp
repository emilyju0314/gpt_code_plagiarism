#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int d, s;
    cin >> d;

    vector<int> l(d);
    for (int i = 0; i < d; i++) {
        cin >> l[i];
    }

    cin >> s;

    vector<vector<long long>> dp(d + 1, vector<long long>(s + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= d; i++) {
        for (int j = 0; j <= s; j++) {
            for (int k = 0; k <= l[i - 1] && k + j <= s; k++) {
                dp[i][j + k] = (dp[i][j + k] + dp[i - 1][j]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= s; i++) {
        ans = (ans + dp[d][i]) % MOD;
    }

    long long factorial = 1;
    for (int i = 1; i <= d; i++) {
        factorial = (factorial * i) % MOD;
    }

    cout << (ans * factorial) % MOD << endl;

    return 0;
}