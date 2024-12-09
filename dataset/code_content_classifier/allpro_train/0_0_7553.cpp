#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define MOD 998244353

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1), transposed_adj(n+1);
    vector<int> dist(n+1, -1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        transposed_adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int nei : adj[curr]) {
            if(dist[nei] == -1) {
                dist[nei] = dist[curr] + 1;
                q.push(nei);
            }
        }
    }

    long long ans = dist[n]; // time taken to move from 1 to n without transposing

    long long time = 0;
    while(ans > 0) {
        ans--;
        time = (time + (1LL << ans)) % MOD;
    }

    cout << time << endl;

    return 0;
}