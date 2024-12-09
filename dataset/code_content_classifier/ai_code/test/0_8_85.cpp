#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
int n, m;
vector<vector<vector<int>>> dp;

int solve(int idx, int min_val, int max_val) {
    if(idx == n) {
        return max_val * min_val >= (min_val + max_val) % m;
    }
    
    if(dp[idx][min_val][max_val] != -1) {
        return dp[idx][min_val][max_val];
    }
    
    int ans = 0;
    for(int i = min_val; i <= n + 1; i++) {
        ans = (ans + solve(idx + 1, min(min_val, i), max(max_val, i))) % m;
    }
    
    return dp[idx][min_val][max_val] = ans;
}

int main() {
    cin >> n >> m;
    
    dp.assign(n, vector<vector<int>>(n + 2, vector<int>(n + 2, -1)));
    
    int ans = solve(0, n + 1, 0);
    
    cout << ans << endl;
    
    return 0;
}