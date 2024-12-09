#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    string S;
    cin >> S;
    
    vector<int> l(M), r(M);
    for(int i=0; i<M; i++) {
        cin >> l[i] >> r[i];
    }
    
    vector<int> dp(N+1, 0);
    dp[0] = 1;
    
    for(int i=0; i<M; i++) {
        vector<int> new_dp(N+1, 0);
        vector<int> pref_sum(N+1, 0);
        
        for(int j=0; j<N; j++) {
            pref_sum[j+1] = (pref_sum[j] + dp[j]) % MOD;
        }
        
        for(int j=0; j<N; j++) {
            if(j < l[i] - 1) {
                new_dp[j] = dp[j];
            } else {
                new_dp[j] = (pref_sum[j] - pref_sum[max(0, j - r[i])] + MOD) % MOD;
            }
        }
        
        swap(dp, new_dp);
    }
    
    int ans = 0;
    for(int i=0; i<N; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}