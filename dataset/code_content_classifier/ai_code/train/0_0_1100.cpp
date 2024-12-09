#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> colors;
vector<int> size;

void dfs(int v, int color) {
    colors[v] = color;
    size[color]++;
    for (int u : graph[v]) {
        if (colors[u] == -1) {
            dfs(u, 1 - color);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    colors.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        // Explore the connected component of the query segment
        fill(colors.begin(), colors.end(), -1);
        int total_segments = 0;
        for (int i = l; i <= r; i++) {
            if (colors[i] == -1) {
                size.assign(2, 0);
                dfs(i, 0);
                total_segments += size[0] * size[1];
            }
        }

        // Print the number of suitable subsegments
        cout << (r - l + 1) * (r - l + 2) / 2 - total_segments << "\n";
    }

    return 0;
}