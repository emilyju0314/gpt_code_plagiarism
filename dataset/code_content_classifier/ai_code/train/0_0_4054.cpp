#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> adj(N+1);
    vector<int> a(N), v(N);
    
    for (int i = 1; i < N; i++) {
        int ai, vi;
        cin >> ai >> vi;
        a[i] = ai;
        v[i] = vi;
        adj[ai].push_back(i+1);
    }
    
    vector<int> dp(N+1, 0);
    
    for (int i = N; i > 0; i--) {
        int maxVal = 0;
        int sum = 0;
        
        for (int child : adj[i]) {
            maxVal = max(maxVal, dp[child]);
            sum += dp[child];
        }
        
        dp[i] = maxVal + sum;
        if (i != 1) dp[i] += v[i-1];
    }
    
    cout << dp[1] << endl;
    
    return 0;
}