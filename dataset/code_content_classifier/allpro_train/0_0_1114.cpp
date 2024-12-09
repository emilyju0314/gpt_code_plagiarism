#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    string s;
    cin >> s;

    vector<bool> visited(N + 1, false);
    queue<int> q;
    vector<int> dist(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        if (s[i - 1] == '1') {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                dist[u] = dist[v] + 1;
            }
        }
    }

    int black_vertices = 0;
    for (int i = 1; i <= N; i++) {
        if (s[i - 1] == '1') {
            int d = dist[i];
            black_vertices = max(black_vertices, d);
        }
    }

    int white_vertices = N - black_vertices;
    int result = white_vertices + 1;

    cout << result << endl;

    return 0;
}