#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> restrictions(n);
    for(int i = 0; i < n; i++) {
        cin >> restrictions[i].first >> restrictions[i].second;
    }
    
    vector<long long> c(k);
    for(int i = 0; i < k; i++) {
        cin >> c[i];
    }
    
    long long dp[2][1 << k];
    memset(dp, 0, sizeof(dp));
    int cur = 0, prev = 1;
    
    for(int i = n - 2; i >= 0; i--) {
        swap(cur, prev);
        for(int mask = 0; mask < (1 << k); mask++) {
            dp[cur][mask] = LLONG_MAX;
            for(int j = 0; j < (1 << k); j++) {
                int next_val = (j ^ mask);
                if(next_val >= restrictions[i].first && next_val <= restrictions[i].second) {
                    dp[cur][mask] = min(dp[cur][mask], dp[prev][j] + c[__builtin_popcount(next_val)]);
                }
            }
        }
    }
    
    long long min_cost = LLONG_MAX;
    for(int i = 0; i < (1 << k); i++) {
        min_cost = min(min_cost, dp[cur][i]);
    }
    
    cout << min_cost << endl;
    
    return 0;
}