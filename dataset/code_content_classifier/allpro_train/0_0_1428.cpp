#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(n));
    
    for(int j = 0; j < n; j++) {
        dp[0][j] = a[j];
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = i; j < n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + a[j];
        }
    }
    
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        int xi, yi;
        cin >> xi >> yi;
        cout << dp[xi-1][yi-1] << endl;
    }
    
    return 0;
}