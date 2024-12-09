#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, s;
        cin >> u >> v >> s;
        u--; v--;
        graph[u].push_back({v, s});
        graph[v].push_back({u, s});
    }

    vector<int> color(n, -1);
    color[0] = 1;

    for (auto edge : graph[0]) {
        color[edge.first] = edge.second - color[0];
    }

    int ans = 1;
    for (auto edge : graph[0]) {
        if (edge.second < color[0] + color[edge.first]) {
            ans = 0;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}