#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<vector<pair<int, vector<int>>>> graph;
vector<vector<vector<int>>> dp;

void add_mod(int& a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    cin >> n >> m;

    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        vector<int> visions(k);
        for (int j = 0; j < k; j++) {
            cin >> visions[j];
        }
        graph[x].push_back({y, visions});
    }

    dp.assign(2 * n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
    for (int i = 1; i <= n; i++) {
        dp[0][i][i] = 1;
    }

    for (int length = 1; length <= 2 * n; length++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (auto& neighbour : graph[i]) {
                    int dest = neighbour.first;
                    vector<int>& visions = neighbour.second;
                    int contrib = dp[length - 1][i][j];
                    if (contrib == 0) {
                        continue;
                    }
                    for (int k = 0; k < visions.size(); k++) {
                        if (length % 2 == 1 && j == visions[k] && i != dest) {
                            add_mod(dp[length][dest][visions[k]], contrib);
                        } else if (length % 2 == 0 && i == visions[k]) {
                            add_mod(dp[length][dest][j], contrib);
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        int result = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                add_mod(result, dp[i][j][k]);
            }
        }
        cout << result << endl;
    }

    return 0;
}