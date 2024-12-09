#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& a, int l, int r, int k) {
    int n = r - l + 1;
    const int inf = 1e9;
    vector<vector<int>> dp(n, vector<int>(31, inf));
    dp[0][0] = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int x = max(0, i - a[l + i - 1]); x < i; x++) {
                dp[i][j] = min(dp[i][j], dp[x][j - (i - x)]);
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        }
    }
    
    return dp[n-1][k];
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        cout << solve(a, l, r, k) << endl;
    }
    
    return 0;
}