#include <iostream>
#include <string>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    string S;
    cin >> S;
    
    int n = S.size();
    
    vector<long long> dp(3, 1);
    
    for(int i=0; i<n; i++) {
        vector<long long> new_dp(3, 0);
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                if(S[i] == '?' || S[i] == 'abc'[k]) {
                    new_dp[(j+k)%3] += dp[j];
                    new_dp[(j+k)%3] %= MOD;
                }
            }
        }
        dp = new_dp;
    }
    
    cout << dp[0] << endl;
    
    return 0;
}