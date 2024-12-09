#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<long long, vector<int>> dp;
    dp[1] = {};

    for (int i = 0; i < n; i++) {
        for (auto it = dp.begin(); it != dp.end(); it++) {
            long long prod = it->first * a[i];
            if (prod <= k) {
                vector<int> new_indices = it->second;
                new_indices.push_back(i);
                dp[prod] = new_indices;
            }
        }
    }

    if (dp[k].size() == 0) {
        cout << -1 << endl;
    } else {
        cout << dp[k].size() << endl;
        for (int i = 0; i < dp[k].size(); i++) {
            cout << dp[k][i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}