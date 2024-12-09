#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(366, 0));
        vector<pair<pair<int, int>, int>> applications(n);
        
        for (int i = 0; i < n; i++) {
            int start, end, price;
            cin >> start >> end >> price;
            applications[i] = make_pair(make_pair(start, end), price);
        }
        
        sort(applications.begin(), applications.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
            return a.first.second < b.first.second;
        });
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 365; j++) {
                dp[i][j] = dp[i - 1][j];
                int start = applications[i - 1].first.first;
                int end = applications[i - 1].first.second;
                int price = applications[i - 1].second;
                if (j >= end) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][start - 1] + price);
                }
            }
        }
        
        cout << dp[n][365] << endl;
    }
    
    return 0;
}