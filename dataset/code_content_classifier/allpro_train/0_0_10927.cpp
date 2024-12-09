#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<long long> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    int m;
    cin >> m;
    
    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    vector<long long> cost(n, 0);
    vector<int> max_val(n);
    for(int i = 0; i < n; i++) {
        max_val[i] = i == 0 ? a[i] : max(a[i], max_val[i-1]);
    }
    
    vector<long long> dp(m+1, 0);
    for(int i = 1; i <= m; i++) {
        dp[i] = -1e18;
    }
    
    for(int i = 0; i < n; i++) {
        int pos = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        if(pos > 0) {
            dp[pos] = max(dp[pos], dp[pos-1] + p[i]);
            int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            cost[idx] = max(cost[idx], dp[pos]);
        }
    }
    
    long long min_cost = dp[m];
    for(int i = 0; i < m; i++) {
        if(cost[i] < max_val[b[i]-1]) {
            min_cost = -1;
            break;
        }
    }
    
    if(min_cost >= -1e18) {
        cout << "YES" << endl;
        cout << min_cost << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}