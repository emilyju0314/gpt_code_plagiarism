#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, vector<int>>> vectors;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> v(m);
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            v[x - 1] = 1;
        }
        vectors.push_back({k, v});
    }

    set<int> indices;
    vector<vector<int>> dp((1 << m), vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; j < m; j++) {
            if (vectors[i].second[j] == 1) {
                mask |= (1 << j);
            }
        }
        
        for (int subset = 0; subset < (1 << m); subset++) {
            dp[subset|mask] = max(dp[subset|mask], dp[subset] + 1);
        }

        indices.insert(i);
    }

    int total = dp[(1 << m) - 1];
    cout << total << " " << indices.size() << endl;
    
    for (int index : indices) {
        cout << index + 1 << " ";
    }

    return 0;
}