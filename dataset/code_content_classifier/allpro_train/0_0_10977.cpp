#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    
    vector<int> h(N);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }
    
    long long ans = 1;
    
    for(int i = 0; i < N; i++) {
        vector<vector<long long>> dp(2, vector<long long>(h[i]+1, 0));
        dp[0][0] = 1;
        
        for(int j = 0; j < h[i]; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    for(int m = 0; m < 2; m++) {
                        if(j + l + m == h[i]) continue;
                        dp[k || l || m][j+l+m] += dp[k][j];
                        dp[k || l || m][j+l+m] %= MOD;
                    }
                }
            }
        }
        
        long long sum = 0;
        for(int j = 0; j <= h[i]; j++) {
            sum += dp[1][j];
            sum %= MOD;
        }
        
        ans *= sum;
        ans %= MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}