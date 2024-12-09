#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m, q;
unordered_set<int> adj[300001];
bool visited[300001];
vector<pair<int, int>> queries;
vector<vector<int>> paths;

void addEdge(int u, int v) {
    adj[u].insert(v);
    adj[v].insert(u);
}

void dfs(int u, int par, vector<int>& path) {
    visited[u] = true;
    path.push_back(u);
    
    if(u == par) {
        paths.push_back(path);
        return;
    }
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v, par, path);
        }
    }
    
    path.pop_back();
}

void solve() {
    bool possible = true;
    
    for(int i = 0; i < q; i++) {
        int a = queries[i].first;
        int b = queries[i].second;
        
        vector<int> path;
        fill(visited, visited+n+1, false);
        
        dfs(a, b, path);
        
        if(paths.size() == 1) {
            possible = false;
            break;
        } else {
            for(int j = 0; j < paths[0].size() - 1; j++) {
                int u = paths[0][j];
                int v = paths[0][j+1];
                adj[u].erase(v);
                adj[v].erase(u);
            }
        }
    }
    
    if(possible) {
        cout << "YES" << endl;
        for(auto path : paths) {
            cout << path.size() << endl;
            for(int node : path) {
                cout << node << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
        cout << "2" << endl;
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        addEdge(x, y);
    }
    
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }
    
    solve();
    
    return 0;
}