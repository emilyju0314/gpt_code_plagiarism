#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> init(n + 1);
    vector<int> goal(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> init[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> goal[i];
    }

    vector<int> ans;
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> cnt(n + 1, 0);
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        if(init[node] != goal[node]) {
            ans.push_back(node);
            init[node] = 1 - init[node];

            for(int v : adj[node]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    cnt[v] = cnt[node] + 1;
                }
            }
        }
    }

    cout << ans.size() << endl;
    for(int x : ans) {
        cout << x << endl;
    }

    return 0;
}