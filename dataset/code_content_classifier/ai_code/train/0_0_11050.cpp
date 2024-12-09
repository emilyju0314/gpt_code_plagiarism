#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 3e5+5;
vector<int> adj[MAXN];
vector<int> police;
int visited[MAXN];

pair<int, vector<int>> dfs(int u, int p, int d) {
    vector<int> dist;
    for (int v : adj[u]) {
        if (v != p) {
            pair<int, vector<int>> res = dfs(v, u, d);
            dist.push_back(res.first);
            for (int road : res.second) {
                if (road != -1) {
                    road++;
                    return {road, res.second};
                }
            }
        }
    }
    
    sort(dist.begin(), dist.end(), greater<int>());
    if (dist.empty()) {
        return {0, {}};
    }
    
    if (dist.size() >= 2 && dist[0] >= d) {
        return {dist[0], {-1}};
    } else {
        return {dist[0] + 1, {dist[0] + 1}};
    }
}

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    
    for (int i = 0; i < k; ++i) {
        int p;
        cin >> p;
        police.push_back(p);
    }
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    pair<int, vector<int>> res = dfs(1, -1, d);
    cout << res.first << endl;
    
    for (int road : res.second) {
        if (road != -1) {
            cout << road << " ";
        }
    }
    
    return 0;
}