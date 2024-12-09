#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    vector<int> A(2*N);
    for (int i = 0; i < 2*N; i++) {
        cin >> A[i];
    }

    int dp[302][302] = {0};
    dp[0][0] = 1;

    int cnt = 0;
    for (int i = 0; i < 2*N; i++) {
        if (A[i] == -1) {
            cnt++;
            for (int x = cnt; x >= 0; x--) {
                for (int y = 0; y <= N; y++) {
                    if (dp[x][y] == 0) continue;
                    if (y < N) {
                        dp[x+1][y+1] = (dp[x+1][y+1] + dp[x][y]) % MOD;
                    }
                    dp[x][y] = (dp[x][y] * x) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int y = 0; y <= N; y++) {
        ans = (ans + dp[cnt][y]) % MOD;
    }

    cout << ans << endl;
    
    return 0;
}