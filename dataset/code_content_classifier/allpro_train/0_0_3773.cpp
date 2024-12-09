#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100001];
int color[100001];

bool isBipartite(int node) {
    queue<int> q;
    q.push(node);
    color[node] = 1;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int next : graph[curr]) {
            if (color[next] == color[curr]) {
                return false;
            }
            if (color[next] == 0) {
                color[next] = 3 - color[curr];
                q.push(next);
            }
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (!isBipartite(i)) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    
    cout << 1 << endl;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    cout << 1 << endl;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 2) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    return 0;
}