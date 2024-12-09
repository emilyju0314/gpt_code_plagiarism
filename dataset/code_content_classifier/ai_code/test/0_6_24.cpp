#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;

vector<pair<int, int>> graph[MAXN];
int dist[MAXN];
int dp[MAXN], last_dp[MAXN];
vector<pair<int, int>> incidents;
vector<int> costs;
vector<int> ans;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++) {
        int w;
        cin >> w;
        costs.push_back(w);
        ans.push_back(0);
    }

    for(int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    for(int i = 0; i < q; i++) {
        int k, x;
        cin >> k >> x;
        incidents.push_back({k, x});
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            dist[i] = 1e9;
            dp[i] = 1e9;
        }

        dist[k] = 0; // starting from station k
        for(int t1 = 0; t1 < 2; t1++) {
            for(int i = 1; i <= n; i++) {
                for(pair<int, int> p : graph[i]) {
                    int j = p.first;
                    int l = p.second;
                    if(dist[j] > dist[i] + l) {
                        dist[j] = dist[i] + l;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            dp[i] = dist[i];
        }

        sort(dp + 1, dp + n + 1);
        last_dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            last_dp[i] = last_dp[i - 1] + dp[i];
        }

        for(int i = 0; i < q; i++) {
            int k = incidents[i].first;
            int x = incidents[i].second;
            int cur_cost = dp[k] + max(0, x - costs[k - 1]);
            ans[i] = max(ans[i], cur_cost);
            ans[i + 1] = max(ans[i + 1], ans[i]);
        }
    }

    for(int i = 0; i <= q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}