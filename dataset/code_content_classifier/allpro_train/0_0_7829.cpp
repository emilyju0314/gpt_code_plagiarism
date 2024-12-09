#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1);
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    vector<int> g_values(2), s_values(2);

    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    cin >> g_values[0] >> g_values[1] >> s_values[0] >> s_values[1];

    for(int i = 1; i <= n; i++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});
        dist[i][i] = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if(d > dist[i][u]) continue;

            for(auto edge : adj[u]) {
                int v = edge.first;
                int c = edge.second;

                if(dist[i][u] + c < dist[i][v]) {
                    dist[i][v] = dist[i][u] + c;
                    pq.push({dist[i][v], v});
                }
            }
        }
    }

    vector<vector<vector<vector<long long>>> dp(n+1, vector<vector<vector<long long>>>(g_values[1]+1, vector<vector<long long>>(s_values[1]+1, vector<long long>(n-g_values[1]-s_values[1]+1, 0)));
    dp[0][0][0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= g_values[1]; j++) {
            for(int k = 0; k <= s_values[1]; k++) {
                for(int l = 0; l <= n-g_values[1]-s_values[1]; l++) {
                    if(j > 0) { // check if we can give gold medal
                        dp[i][j][k][l] += dp[i-1][j-1][k][l];
                    }
                    if(k > 0) { // check if we can give silver medal
                        dp[i][j][k][l] += dp[i-1][j][k-1][l];
                    }
                    if(l > 0) { // check if we can give bronze medal
                        dp[i][j][k][l] += dp[i-1][j][k][l-1];
                    }
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n-g_values[1]-s_values[1]; j++) {
            ans += dp[n][g_values[1]][s_values[1]][j] * (i==1 || dist[i][i] > dist[i][i-1]);
        }
    }

    cout << ans << endl;

    return 0;
}