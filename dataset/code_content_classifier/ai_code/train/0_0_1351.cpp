#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN], colors[MAXN];
bool visited[MAXN];

void dfs(int u, int color) {
    visited[u] = true;
    colors[color].push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, color);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (c == 'R') {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int color = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, color);
            color++;
        }
    }

    vector<int> result;
    for (int i = 0; i < color; i++) {
        bool all_same = true;
        for (int j : colors[i]) {
            for (int v : adj[j]) {
                if (binary_search(colors[i].begin(), colors[i].end(), v)) {
                    continue;
                } else {
                    all_same = false;
                    break;
                }
            }
            if (!all_same) {
                break;
            }
        }
        if (!all_same) {
            cout << "-1" << endl;
            return 0;
        }
        result.push_back(colors[i].front());
    }

    cout << result.size() << endl;
    for (int u : result) {
        cout << u << " ";
    }
    cout << endl;

    return 0;
}