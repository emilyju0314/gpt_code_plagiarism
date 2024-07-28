#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> in_degree, out_degree;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

bool isEulerian() {
    int start_nodes = 0, end_nodes = 0;
    for (int i = 0; i < 26; i++) {
        int diff = in_degree[i] - out_degree[i];
        if (diff < -1 || diff > 1) {
            return false;
        }
        if (diff == 1) {
            start_nodes++;
        }
        else if (diff == -1) {
            end_nodes++;
        }
    }
    if (start_nodes == 0 && end_nodes == 0) {
        return true;
    }
    if (start_nodes == 1 && end_nodes == 1) {
        return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        adj.assign(26, vector<int>());
        in_degree.assign(26, 0);
        out_degree.assign(26, 0);
        visited.assign(26, false);
        for (int i = 0; i < n; i++) {
            string word;
            cin >> word;
            int u = word[0] - 'a';
            int v = word[word.length() - 1] - 'a';
            adj[u].push_back(v);
            out_degree[u]++;
            in_degree[v]++;
        }
        int start = -1;
        for (int i = 0; i < 26; i++) {
            if (out_degree[i] - in_degree[i] == 1) {
                start = i;
                break;
            }
        }
        if (start == -1) {
            for (int i = 0; i < 26; i++) {
                if (out_degree[i] > 0) {
                    start = i;
                    break;
                }
            }
        }
        dfs(start);

        bool eulerian = true;
        for (int i = 0; i < 26; i++) {
            if ((out_degree[i] > 0 || in_degree[i] > 0) && !visited[i]) {
                eulerian = false;
                break;
            }
        }

        if (eulerian && isEulerian()) {
            cout << "Ordering is possible.\n";
        }
        else {
            cout << "The door cannot be opened.\n";
        }

        if (T > 0) {
            cout << "\n";
        }
    }

    return 0;
}