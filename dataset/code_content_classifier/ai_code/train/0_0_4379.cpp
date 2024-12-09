#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int dist[MAXN];
int universities[MAXN];

void dfs(int u, int p, int d) {
    dist[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < 2 * k; i++) {
        int u;
        cin >> u;
        universities[u] = 1;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, -1, 0);
    
    vector<int> distances;
    for (int i = 1; i <= n; i++) {
        if (universities[i]) {
            distances.push_back(dist[i]);
        }
    }
    
    sort(distances.begin(), distances.end(), greater<int>());
    
    int total_distance = 0;
    for (int i = 0; i < 2 * k; i += 2) {
        total_distance += distances[i];
    }
    
    cout << total_distance << endl;
    
    return 0;
}