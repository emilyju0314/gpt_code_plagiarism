#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> count(1000000);
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    vector<long long> dp(1000000, 0);
    for (int p = 0; p < 20; p++) {
        for (int x = 0; x < 1000000; x++) {
            if ((x & (1 << p)) > 0) {
                dp[x] += count[x];
            } else {
                dp[x ^ (1 << p)] += count[x];
            }
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < 1000000; i++) {
        long long val = pow(dp[i], 2);
        val %= MOD;
        val *= i;
        val %= MOD;
        ans ^= val;
    }
    
    cout << ans << endl;
    
    return 0;
}