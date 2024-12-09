#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[500005];
bool visited[500005];
int parent[500005];
bool used[500005];
vector<pair<int, int>> pairs;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = curr;
                q.push(next);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = false;
            used[i] = false;
        }
        pairs.clear();

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int start = 1;
        bfs(start);

        int current_node = 1, path_length = 0;
        vector<int> path;
        while (current_node != -1) {
            path.push_back(current_node);
            current_node = parent[current_node];
            path_length++;
        }

        if (path_length >= (n + 1) / 2) {
            cout << "PATH\n";
            cout << path_length << "\n";
            for (int i = path_length - 1; i >= 0; i--) {
                cout << path[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "PAIRING\n";
            int pair_count = (n + 1) / 2;
            int pair_index = 0;

            for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                    int current_pair = 0;
                    pairs.push_back({i, 0});
                    used[i] = true;

                    for (int j = 1; j <= n; j++) {
                        if (!used[j] && adj[i].size() + adj[j].size() <= 2) {
                            pairs[pair_index].second = j;
                            pairs.push_back({0, 0});
                            used[j] = true;
                            current_pair++;
                            pair_index++;
                        }

                        if (current_pair == 2) break;
                    }
                }
            }

            cout << pairs.size() << "\n";
            for (auto p : pairs) {
                cout << p.first << " " << p.second << "\n";
            }
        }
    }

    return 0;
}