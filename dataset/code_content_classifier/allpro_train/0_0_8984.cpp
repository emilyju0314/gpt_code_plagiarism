#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> adj(N+1);
    vector<int> parent(N+1);
    vector<int> depth(N+1);
    vector<int> c(N+1);

    for(int i=1; i<N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    parent[1] = -1;
    depth[1] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(v == parent[u]) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            q.push(v);
        }
    }

    for(int i=2; i<=N; i++) {
        int x = i;
        while(x != 1) {
            c[i]++;
            x = parent[x];
        }
    }

    for(int i=2; i<=N; i++) {
        cout << c[i] << " ";
    }

    return 0;
}