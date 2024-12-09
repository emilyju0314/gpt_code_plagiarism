#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int distAlice[MAXN], distBob[MAXN];

int dfs(int u, int parent = -1, int depth = 0) {
    distAlice[u] = depth;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u, depth + 1);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k;
    cin >> k;
    vector<int> bobs;
    for (int i = 0; i < k; i++) {
        int pos;
        cin >> pos;
        bobs.push_back(pos);
    }

    dfs(1); // Calculate distances for Alice

    queue<int> q;
    for (int initPos : bobs) {
        q.push(initPos);
        distBob[initPos] = 0;
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (distBob[v] == 0) continue; // Already visited
            distBob[v] = distBob[u] + 1;
            q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << min(distAlice[i], distBob[i]) << " ";
    }
    cout << endl;

    return 0;
}