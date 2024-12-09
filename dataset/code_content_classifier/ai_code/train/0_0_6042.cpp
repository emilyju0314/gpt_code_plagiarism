#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    
    vector<int> x(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i];
    }
    
    vector<long long> dp(N+1, 0);
    dp[0] = 1;
    
    for(int i = 1; i < N; i++) {
        int pos = x[i] - 1;
        if(pos >= 2) {
            dp[i] += dp[pos - 1];
            dp[i] %= MOD;
        }
        
        dp[i] += dp[pos];
        dp[i] %= MOD;
    }
    
    cout << dp[N-1] << endl;
    
    return 0;
}