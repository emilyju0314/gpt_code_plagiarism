#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    vector<vector<long long>> dp(C+1, vector<long long>(C+1));
    dp[0][0] = 1;

    for(int i = 0; i <= C; i++) {
        for(int j = 1; j <= C; j++) {
            for(int k = 0; k <= i; k++) {
                dp[i][j] = (dp[i][j] + dp[i-k][j-1]) % MOD;
            }
        }
    }

    vector<vector<long long>> s(C+1, vector<long long>(C+1));
    for(int i = 0; i <= C; i++) {
        s[i][0] = 1;
    }

    for(int i = 1; i <= C; i++) {
        for(int j = 1; j <= C; j++) {
            s[i][j] = (s[i][j-1] + dp[i][j]) % MOD;
        }
    }

    long long ans = 0;
    for(int c = 1; c <= C; c++) {
        for(int i = 0; i < N; i++) {
            for(int j = c; j <= C; j++) {
                ans = (ans + dp[j][c] * s[C-j][B[i]-A[i]]) % MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}