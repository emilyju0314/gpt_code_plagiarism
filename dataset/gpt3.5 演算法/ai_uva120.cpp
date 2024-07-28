#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 10056;
int dp[1001] = {0};

void calculate_dp() {
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += (dp[i - j] * dp[j - 1]) % MOD;
            dp[i] %= MOD;
        }
    }
}

int main() {
    calculate_dp();
    
    int T;
    cin >> T;
    
    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int n;
        cin >> n;
        
        cout << "Case " << caseNum << ": " << dp[n] << endl;
    }

    return 0;
}
