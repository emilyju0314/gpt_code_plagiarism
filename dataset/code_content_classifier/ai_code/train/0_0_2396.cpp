#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long long MOD = 1e9 + 7;

vector<vector<pair<int, int>>> adj; // adjacency list to store the cobweb
long long jelliness = 1;

pair<int, int> dfs(int node, int parent, int red_count, int black_count, long long clamminess) {
    pair<int, int> result = {0, 0}; // red_count and black_count pairs

    for (auto edge : adj[node]) {
        int next_node = edge.first;
        int color = edge.second;

        if (next_node != parent) {
            if (color == 0) {
                red_count++;
            } else {
                black_count++;
            }

            pair<int, int> child = dfs(next_node, node, red_count, black_count, clamminess * edge.first);

            result.first += child.first;
            result.second += child.second;

            if (abs(result.first - result.second) <= 2) {
                jelliness = (jelliness * clamminess) % MOD;
            }
        }
    }

    return {red_count, black_count};
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v, x, c;
        cin >> u >> v >> x >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dfs(1, 0, 0, 0, 1);

    cout << jelliness << endl;

    return 0;
}