#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> roads(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1];
    }

    vector<int> dp(n);
    dp[0] = c[0];

    for (int i = 0; i < m; i++) {
        int a = roads[i][0];
        int b = roads[i][1];
        dp[b] = max(dp[b], dp[a] + c[b]);
    }

    int max_satisfaction = 0;
    for (int i = 0; i < n; i++) {
        max_satisfaction = max(max_satisfaction, dp[i]);
    }

    cout << max_satisfaction << endl;

    return 0;
}