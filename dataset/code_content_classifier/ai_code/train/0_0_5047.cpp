#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> tunnels(n+1);
    vector<int> degree(n+1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        tunnels[u].push_back(v);
        tunnels[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    int min_lines = 0, max_lines = 0;

    for (int i = 1; i <= n; i++) {
        min_lines = max(min_lines, degree[i]);
    }

    for (int i = 1; i <= n; i++) {
        max_lines = max(max_lines, degree[i]);
    }

    cout << (min_lines + 1) / 2 << " " << max_lines << endl;

    return 0;
}