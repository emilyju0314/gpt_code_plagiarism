#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int dp[1005][1005];

void computeBeautySequences() {
    for(int i = 1; i <= 1000; i++) {
        dp[i][1] = 1;
    }

    for(int i = 1; i <= 1000; i++) {
        for(int j = 2; j <= 1000; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-j][j]) % MOD;
        }
    }
}

int main() {
    int t;
    cin >> t;

    computeBeautySequences();

    while(t--) {
        int n, k;
        cin >> n >> k;

        cout << dp[n][k] << "\n";
    }

    return 0;
}