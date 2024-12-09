#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isLucky(int n) {
    while(n > 0) {
        int digit = n % 10;
        if(digit != 4 && digit != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = INT_MAX;
    for(int i = 1; i <= n; i++) {
        vector<int> region;
        vector<bool> visited(n+1, false);

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            region.push_back(node);
            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
        };

        if(!visited[i]) {
            dfs(i);
            int size = region.size();

            int count = 0;
            for(int j = 1; j <= size; j++) {
                if(isLucky(j)) {
                    count = size - j;
                    break;
                }
            }

            if(isLucky(size)) {
                ans = min(ans, count);
            }
        }
    }

    if(ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}