#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    vector<int> p(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<double> dp(1 << n, 0);
    dp[0] = 0;
    
    for (int mask = 1; mask < (1 << n); mask++) {
        double prob = 1.0;
        int val = 1;
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                prob *= p[i] / 100.0;
                val = (val * a[i]) / __gcd(val, a[i]);
            }
        }
        
        dp[mask] = dp[mask ^ mask & -mask] + (m / val) * prob;
        
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
            dp[mask] -= dp[sub];
        }
    }
    
    cout.precision(7);
    cout << fixed << dp[(1 << n) - 1] << endl;
    
    return 0;
}