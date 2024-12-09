#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 105;

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];
bool isCycle = false;

void dfs(int v, int parent) {
    visited[v] = true;
    
    for(int u: adj[v]) {
        if(u == parent) continue;
        if(visited[u]) {
            isCycle = true;
        } else {
            dfs(u, v);
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    if(m != n) {
        cout << "NO" << endl;
        return 0;
    }
    
    dfs(1, -1);
    
    if(isCycle) {
        cout << "FHTAGN!" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}