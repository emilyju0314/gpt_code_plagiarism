#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> adj[N+1];
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> color(N+1, 0); // 0 for white, 1 for black
    queue<int> q;
    
    q.push(1);
    color[1] = 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (color[v] == 0) {
                color[v] = 3 - color[u]; // Toggle color
                q.push(v);
            } else if (color[v] == color[u]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    int blackCount = 0;
    for (int i = 1; i <= N; i++) {
        if (color[i] == 1) blackCount++;
    }
    
    cout << blackCount - 1 << endl;
    
    return 0;
}