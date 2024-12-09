#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> dp(100001, 0);
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        vector<int> temp_dp(dp);
        for (int j = 0; j <= 100000; j++) {
            temp_dp[j] += dp[j];
            if (temp_dp[j] >= MOD) {
                temp_dp[j] -= MOD;
            }
            int new_gcd = gcd(j, a[i]);
            temp_dp[new_gcd] += dp[j];
            if (temp_dp[new_gcd] >= MOD) {
                temp_dp[new_gcd] -= MOD;
            }
        }
        dp = temp_dp;
    }
    
    int result = 0;
    for (int i = 1; i <= 100000; i++) {
        result += dp[i];
        if (result >= MOD) {
            result -= MOD;
        }
    }
    
    cout << result << endl;
    
    return 0;
}