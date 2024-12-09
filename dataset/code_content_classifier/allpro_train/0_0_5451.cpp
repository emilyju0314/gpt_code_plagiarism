#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<pair<int, int>>> choices(n);
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        choices[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> choices[i][j].first >> choices[i][j].second;
        }
    }
    
    vector<int> dp(n, 0);
    
    for (int i = n - 1; i >= 0; i--) {
        for (auto [nextPoint, time] : choices[i]) {
            dp[i] = max(dp[i], dp[nextPoint-1] + time);
        }
    }
    
    cout << dp[0] << endl;
    
    return 0;
}