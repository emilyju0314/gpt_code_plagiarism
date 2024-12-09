#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int k, w;
    cin >> k >> w;

    vector<long long> dp(w+1, 0);
    dp[1] = k;
    
    long long total = k;
    for(int i=2; i<=w; i++){
        dp[i] = (total * (k-1)) % MOD;
        total += dp[i];
        if(i > w) total -= dp[i-w];
        total = (total % MOD + MOD) % MOD;
    }

    long long answer = pow(k, w) - total;
    if(answer < 0) answer += MOD;
    cout << answer << endl;

    return 0;
}