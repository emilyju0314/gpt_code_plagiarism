#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Edge {
    int u, v, idx;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<Edge> edges(n-1);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(i);
        adj[v].push_back(i);
        edges[i] = {u, v, i};
    }

    vector<int> x(m), y(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }

    int k = n; // minimum number of puppies needed
    vector<int> puppies(n, 0);
    vector<int> ans_citizen, ans_guardian;
    
    for (int i = 0; i < m; i++) {
        queue<int> q;
        vector<int> dist(n, -1);
        int u = x[i], v = y[i];
        dist[u] = 0;
        q.push(u);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == v) {
                break;
            }
            for (int idx : adj[cur]) {
                Edge &e = edges[idx];
                int nxt = e.u ^ e.v ^ cur;
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                    if (nxt != v) {
                        puppies[e.idx]++;
                    }
                }
            }
        }
        
        if (dist[v] == -1) {
            ans_citizen.push_back(i+1);
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        if (puppies[i] == 0) {
            ans_guardian.push_back(i+1);
        }
    }

    cout << k << endl;
    cout << ans_citizen.size() << " ";
    for (int idx : ans_citizen) {
        cout << idx << " ";
    }
    
    cout << endl << ans_guardian.size() << " ";
    for (int idx : ans_guardian) {
        cout << idx << " ";
    }

    return 0;
}