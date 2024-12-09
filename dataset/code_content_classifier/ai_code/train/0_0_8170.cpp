#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> values(n);
    vector<int> colors(n);

    for(int i = 0; i < n; i++) {
        cin >> values[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    vector<pair<int, int>> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    for(auto query : queries) {
        int a = query.first;
        int b = query.second;

        unordered_map<int, long long> dp;
        long long max_value = 0;

        for(int i = 0; i < n; i++) {
            int color = colors[i];
            int value = values[i];
            
            long long current_value = dp[color] + max(0, value * b);

            dp[color] = max(dp[color], max_value + max(0, value * a));
            max_value = max(max_value, current_value);
        }

        cout << max_value << endl;
    }

    return 0;
}