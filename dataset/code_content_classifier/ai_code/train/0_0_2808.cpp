#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int j : adj[i]) {
            if (r[j] > r[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_concerts = *max_element(dp.begin(), dp.end());
    cout << max_concerts << endl;

    return 0;
}