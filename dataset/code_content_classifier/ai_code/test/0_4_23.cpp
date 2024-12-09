#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    vector<vector<long long>> dp(m+1, vector<long long>(n, 0));
    for(int i = 1; i <= m; i++) {
        for(int j = i; j <= n; j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-2] + 1LL * a[j-1] * (2*j - i - 1));
        }
    }
    
    cout << dp[m][n] << endl;

    return 0;
}