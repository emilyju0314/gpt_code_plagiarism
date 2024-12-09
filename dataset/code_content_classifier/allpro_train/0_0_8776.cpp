#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, pair<int, int>>> companies;

    for(int i = 0; i < m; i++) {
        int li, ri, ci;
        cin >> li >> ri >> ci;
        companies.push_back({ci, {li, ri}});
    }

    sort(companies.begin(), companies.end());

    int ans = -1;

    for(int i = 0; i < m; i++) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int j = 0; j < n; j++) {
            for(int p = i; p < m; p++) {
                int l = companies[p].second.first;
                int r = companies[p].second.second;
                int cost = companies[p].first;

                if(j + r <= n) {
                    dp[j + r] = min(dp[j + r], dp[j] + cost);
                }
            }
        }

        if(dp[n] != INT_MAX && dp[n] >= k) {
            if(ans == -1) {
                ans = companies[i].first;
            } else {
                ans = min(ans, companies[i].first);
            }
        }
    }

    cout << ans << endl;

    return 0;
}