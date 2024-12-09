#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 1000000007

using namespace std;

int dp[1000005];

int main() {
    int A, B, C, SX, SY;
    while (true) {
        cin >> A >> B >> C >> SX >> SY;
        if (A == 0 && B == 0 && C == 0 && SX == 0 && SY == 0) {
            break;
        }

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int i = 0; i < A + B + C; i++) {
            for (int j = SX; j >= 0; j--) {
                for (int k = SY; k >= 0; k--) {
                    if (j >= 1) {
                        dp[j] = (dp[j] + dp[j - 1]) % MOD;
                    }
                    if (k >= 1) {
                        dp[k] = (dp[k] + dp[k - 1]) % MOD;
                    }
                }
            }
        }

        cout << dp[SX] << endl;
    }
    
    return 0;
}