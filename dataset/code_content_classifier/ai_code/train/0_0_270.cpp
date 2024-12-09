#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

vector<long long> dp(2000001, 0);

void precompute() {
    dp[3] = 4;
    for(int i = 4; i <= 2000000; i++) {
        dp[i] = (2 * dp[i-1] + dp[i-2] + 4) % MOD;
    }
}

int main() {
    precompute();

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}