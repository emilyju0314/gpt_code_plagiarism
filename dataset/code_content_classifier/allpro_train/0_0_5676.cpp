#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges;
    vector<int> degree(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        degree[a]++;
        degree[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            possible = false;
            break;
        }
    }
    
    if (!possible) {
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    int start = 1, end = 1;
    while (start <= n) {
        for (int i = 0; i < m; i++) {
            if ((edges[i].first == start || edges[i].second == start) && edge[i] > 0) {
                cout << 2 << endl;
                cout << start << " " << edges[i].first << " " << edges[i].second << endl;
                edge[i] = 0;
                start++;
                if (edges[i].first == start) {
                    start = edges[i].second;
                } else {
                    start = edges[i].first;
                }
                break;
            }
        }
    }
    
    return 0;
}