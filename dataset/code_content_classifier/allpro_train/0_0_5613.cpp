#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];

bool dfs(int u, int target, int parent) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (v == target) {
                return true;
            }
            if (dfs(v, target, u)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < N - 1; i++) {
        int c, d;
        cin >> c >> d;

        // Reset visited array for each query
        fill(visited, visited + MAXN, false);

        if (!dfs(c, d, -1)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}