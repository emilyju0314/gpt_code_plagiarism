#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[200001];
vector<bool> visited(200001, false);

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 2 * n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 2) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        cout << "-1" << endl;
    } else {
        dfs(start);
    }

    return 0;
}