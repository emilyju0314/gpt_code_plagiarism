#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    set<int> colors;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        colors.insert(c);
    }

    int result = colors.size() - n + 1;
    cout << result << endl;

    return 0;
}