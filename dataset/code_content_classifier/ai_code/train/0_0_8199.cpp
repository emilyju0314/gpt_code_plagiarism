#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> dp(n, 1e9);
    dp[0] = a[0];
    
    for(int i = 1; i < n; i++) {
        vector<int> pref_sum(i+1);
        pref_sum[0] = a[i];
        for(int j = 1; j <= i; j++) {
            pref_sum[j] = pref_sum[j-1] + a[i-j];
            dp[i] = min(dp[i], dp[i-j] + pref_sum[j] - min(pref_sum[j], c));
        }
    }
    
    cout << dp[n-1] << endl;
    
    return 0;
}