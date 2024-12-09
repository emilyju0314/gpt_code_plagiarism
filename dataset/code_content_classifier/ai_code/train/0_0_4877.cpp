#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> alice_edges(m);
    unordered_map<int, vector<int>> adj_list;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        alice_edges[i] = {a, b};
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    long long triangles = 0;
    for (const auto& edge : alice_edges) {
        int u = edge.first;
        int v = edge.second;

        for (int w : adj_list[u]) {
            if (w == v) continue;
            if (adj_list[v].size() < adj_list[w].size() || 
                (adj_list[v].size() == adj_list[w].size() && v < w)) {
                triangles += adj_list[v].size() - 2;
            }
        }
    }

    cout << triangles << endl;

    return 0;
}