#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> path;
unordered_map<int, vector<vector<int>>> queries;
unordered_map<pair<int, int>, int> edge_parity;

bool dfs(int node, int target) {
    if (visited[node] == 1) return false;
    if (node == target) {
        path.push_back(node);
        return true;
    }
    
    visited[node] = 1;
    for (int next : adj[node]) {
        if (dfs(next, target)) {
            path.push_back(node);
            return true;
        }
    }
    
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n);
    visited.resize(n, 0);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edge_parity[{x, y}] = 0;
        edge_parity[{y, x}] = 0;
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (queries.find(a) == queries.end()) {
            queries[a] = vector<vector<int>>();
        }
        queries[a].push_back({b, i});
    }
    
    for (auto& query_pair : queries) {
        int a = query_pair.first;
        for (vector<int>& query : query_pair.second) {
            int b = query[0];
            visited = vector<int>(n, 0);
            
            if (dfs(a, b)) {
                for (int j = 0; j < path.size() - 1; j++) {
                    int u = path[j], v = path[j+1];
                    edge_parity[{u, v}]++;
                    edge_parity[{v, u}]++;
                }
                
                path.clear();
            } else {
                cout << "NO" << endl;
                cout << "2" << endl;
                return 0;
            }
        }
    }
    
    cout << "YES" << endl;
    for (auto& query_pair : queries) {
        int a = query_pair.first;
        for (vector<int>& query : query_pair.second) {
            int b = query[0];
            cout << 2 << endl;
            cout << a+1 << " ";
            cout << b+1 << endl;
        }
    }
    
    return 0;
}