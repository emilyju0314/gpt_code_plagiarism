#include <iostream>
#include <vector>
using namespace std;

const int mod = 998244353;

int main() {
    int N, X;
    cin >> N >> X;

    vector<vector<long long>> dp(N + 1, vector<long long>(X + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= X; j++) {
            for (int k = 0; k < j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
            }
        }
    }

    cout << dp[N][X] << endl;

    return 0;
}