#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 3e5 + 5;
vector<int> adj[N];
int visited[N];
int path[N];

bool bfs(int start, int end, int n) {
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        path[i] = 0;
    }

    queue<int> q;
    q.push(start);
    visited[start] = 1;
    path[start] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = 1;
                path[v] = u;
            }
        }
    }

    return visited[end];
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int q;
    cin >> q;

    vector<pair<int, int>> queries;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }

    vector<pair<int, int>> output;

    for (auto query : queries) {
        int a = query.first;
        int b = query.second;

        if (bfs(a, b, n)) {
            int cur = b;
            vector<int> current_path;
            while (cur != -1) {
                current_path.push_back(cur);
                cur = path[cur];
            }
            output.push_back({current_path.size(), i});
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    for (auto path_data : output) {
        cout << path_data.first << endl;
        for (int node : adj[path_data.second]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}