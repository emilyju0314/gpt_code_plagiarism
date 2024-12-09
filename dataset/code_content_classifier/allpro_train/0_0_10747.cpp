#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 998244353;

int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    
    long long result = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            break;
        }
        if(s[i] == '1' || s[i] == '?') {
            result = (result + dp[i]) % MOD;
        }
    }
    
    cout << result << endl;
    
    return 0;
}