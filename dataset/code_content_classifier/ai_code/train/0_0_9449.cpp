#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string colors;
    cin >> colors;
    
    int whiteCnt = 0;
    for(char color : colors) {
        if(color == 'W') {
            whiteCnt++;
        }
    }

    if(whiteCnt == 0) {
        cout << "White\n";
        return;
    } else if(whiteCnt == 1) {
        cout << "Draw\n";
        return;
    }
    
    // Start from the first uncolored vertex
    int root = -1;
    for(int i = 0; i < n; i++) {
        if(colors[i] == 'N') {
            root = i;
            break;
        }
    }
    
    vector<int> subtree(n, 0);
    queue<int> q;
    q.push(root);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : adj[u]) {
            if(colors[v] == 'N') {
                subtree[u]++;
                q.push(v);
            }
        }
    }
    
    int blackCnt = n - whiteCnt;
    if(subtree[root] >= 3 || (subtree[root] == 2 && blackCnt % 2 == 0)) {
        cout << "Black\n";
        return;
    } else {
        cout << "Draw\n";
        return;
    }
}

int main() {
    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        solve();
    }

    return 0;
}