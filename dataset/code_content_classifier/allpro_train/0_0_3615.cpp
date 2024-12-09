#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(2*N, vector<int>(2*N));
    for (int i = 0; i < 2*N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < 2*N; j++) {
            A[i][j] = row[j] - '0';
        }
    }

    vector<vector<long long>> dp(1<<N, vector<long long>(N));
    dp[0][0] = 1;

    for (int s = 0; s < (1<<N); s++) {
        int divisible_pairs = __builtin_popcount(s) / 2;
        for (int i = 0; i < N; i++) {
            if (s & (1<<i)) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (!(s & (1<<j)) && A[i][N+j] == 1) {
                    dp[s | (1<<i) | (1<<j)][divisible_pairs+1] += dp[s][divisible_pairs];
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += dp[(1<<N)-1][i];
    }

    cout << ans << endl;

    return 0;
}