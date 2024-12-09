#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> rank;
vector<vector<int>> adj;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    
    rank[start] = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int u : adj[v]) {
            if (rank[u] == -1) {
                rank[u] = (rank[v] + 1) % 26;
                q.push(u);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    rank.resize(n, -1);
    adj.resize(n);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(0);
    
    for (int i = 0; i < n; i++) {
        if (rank[i] == -1) {
            cout << "Impossible!";
            return 0;
        }
    }
    
    for (int r : rank) {
        cout << char('A' + r) << " ";
    }
    
    return 0;
}