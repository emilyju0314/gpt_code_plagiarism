#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 201;

int dp[MAX_N][MAX_N];

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N-1), b(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> a[i] >> b[i];
    }
    
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k <= j; k++) {
                if (a[j] > a[i-1] && b[j] > b[i-1]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                }
                if (a[j] < a[i-1] && b[j] < b[i-1]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + dp[N-1][i]) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}