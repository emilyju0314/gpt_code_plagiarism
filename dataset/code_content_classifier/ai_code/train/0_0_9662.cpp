#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<vector<int>> adj;
vector<int> statues, desired, dist;

void buildTree(int u, int parent) {
    for (int v : adj[u]) {
        if (v != parent) {
            buildTree(v, u);
            dist[u] = min(dist[u], dist[v] + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    statues.resize(n + 1);
    desired.resize(n + 1);
    dist.assign(n + 1, INF);

    for (int i = 1; i <= n; i++) {
        cin >> statues[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> desired[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dist[1] = 0;
    buildTree(1, 0);

    int moves = 0;
    int emptyIsland = 0;

    for (int i = 1; i <= n; i++) {
        if (desired[i] == 0) {
            emptyIsland = i;
        } else if (desired[i] != statues[i]) {
            if (dist[i] < dist[emptyIsland]) {
                emptyIsland = i;
            }
            moves++;
        }
    }

    if (emptyIsland == 0) {
        cout << "0 " << moves << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            if (i != emptyIsland && desired[i] == statues[i] && dist[i] < dist[emptyIsland]) {
                cout << i << " " << emptyIsland << " " << (moves + dist[i] - 1) << endl;
                return 0;
            }
        }
        cout << "-1" << endl;
    }

    return 0;
}