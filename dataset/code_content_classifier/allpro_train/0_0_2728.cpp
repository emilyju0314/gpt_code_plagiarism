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

    vector<pair<int, int>> queries(m);
    for(int i = 0; i < m; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<vector<int>> dp(n, vector<int>(n));
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = max(max(dp[i][j-1], dp[i+1][j]), a[j] - a[i]);
        }
    }

    for(int i = 0; i < m; i++) {
        int l = queries[i].first - 1;
        int r = queries[i].second - 1;
        cout << dp[l][r] << endl;
    }

    return 0;
}