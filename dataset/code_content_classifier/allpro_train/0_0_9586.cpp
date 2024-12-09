#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[i] = make_pair(a, b);
    }

    int w = 0;
    vector<vector<int>> episodes;

    for (auto edge : edges) {
        int x = edge.first, y = edge.second;
        for (int z : adj[x]) {
            if (z != y) {
                episodes.push_back({x, y, z});
                w++;
                break;
            }
        }
        if (w >= n) break;
    }

    cout << w << endl;
    for (auto episode : episodes) {
        for (int city : episode) {
            cout << city << " ";
        }
        cout << endl;
    }

    return 0;
}