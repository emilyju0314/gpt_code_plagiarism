#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MOD 1000000009

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> pairs(N + 1, -1);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        pairs[x] = y;
        pairs[y] = x;
    }

    vector<int> dp(N + 1, 0);
    vector<int> dpsum(N + 1, 0);

    dp[0] = 1;
    dp[1] = 1;
    dpsum[0] = 1;
    dpsum[1] = 2;

    for (int i = 2; i <= N; i++) {
        if (pairs[i] == i - 1) {
            dp[i] = (dpsum[i - 2] + dpsum[i - 1] - dp[pairs[i]]) % MOD;
        }
        else {
            dp[i] = (dpsum[i - 1] - dp[pairs[i]]) % MOD;
        }

        dpsum[i] = (dpsum[i - 1] + dp[i]) % MOD;
    }

    cout << dpsum[N] << endl;

    return 0;
}