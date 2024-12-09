#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int node, vector<vector<int>>& adj_list, vector<int>& s, vector<int>& f, vector<bool>& visited) {
    visited[node] = true;
    int total_flow = s[node];
    for (int neighbor : adj_list[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj_list, s, f, visited)) {
                total_flow += f[make_pair(node, neighbor)];
            } else {
                total_flow += f[make_pair(neighbor, node)];
            }
        }
    }

    if (node == 0) return total_flow == s[0];
    else return total_flow == 0;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> s(n);
    int total_flow = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        total_flow += s[i];
    }

    cin >> m;
    vector<vector<int>> adj_list(n);
    vector<pair<int, int>> pipes;
    vector<int> f(m);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
        pipes.push_back({x, y});
    }

    if (total_flow != 0) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i] && !dfs(i, adj_list, s, f, visited)) {
                cout << "Impossible" << endl;
                return 0;
            }
        }

        for (int i = 0; i < m; i++) {
            int x = pipes[i].first;
            int y = pipes[i].second;
            if (f[make_pair(x, y)] == 0) {
                f[make_pair(x, y)] = s[x];
                f[make_pair(y, x)] = -s[x];
            }
            cout << f[make_pair(x, y)] << endl;
        }
    }

    return 0;
}