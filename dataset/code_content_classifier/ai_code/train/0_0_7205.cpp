#include <bits/stdc++.h>
using namespace std;

vector<int> tree[1001];
int dist[1001], s, f;

void dfs(int v, int p, int d) {
    dist[v] = d;
    for (int u : tree[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
        }
    }
}

pair<int, int> query(vector<int>& nodes) {
    cout << "? " << nodes.size();
    for (int node : nodes) {
        cout << " " << node;
    }
    cout << endl;
    
    int x, d;
    cin >> x >> d;
    return make_pair(x, d);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            tree[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<int> nodes;
        for (int i = 1; i <= n; i++) {
            nodes.push_back(i);
        }

        pair<int, int> result = query(nodes);
        s = result.first;
        
        vector<int> s_nodes;
        for (int i = 1; i <= n; i++) {
            if (i != s) {
                s_nodes.push_back(i);
            }
        }

        result = query(s_nodes);
        f = result.first;

        dfs(s, -1, 0);
        
        int max_dist = 0;
        for (int i = 1; i <= n; i++) {
            max_dist = max(max_dist, dist[i]);
        }

        vector<int> candidates;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == max_dist) {
                candidates.push_back(i);
            }
        }

        result = query(candidates);

        cout << "! " << s << " " << f << endl;
        string response;
        cin >> response;
    }

    return 0;
}