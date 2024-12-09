#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> colors;
vector<vector<int>> tree;
vector<int> subtreeSizes;
unordered_map<int, int> colorCounts;

void dfs(int node, int parent) {
    subtreeSizes[node] = 1;
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
            subtreeSizes[node] += subtreeSizes[child];
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    colors.resize(n);
    tree.resize(n);
    subtreeSizes.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        colorCounts[colors[i]]++;
    }

    for (int query = 0; query < m; query++) {
        int v, k;
        cin >> v >> k;
        v--;

        int totalColors = 0;
        for (pair<int, int> colorCount : colorCounts) {
            if (colorCount.second >= k && (subtreeSizes[v] - colorCounts[colorCount.first]) >= k) {
                totalColors++;
            }
        }

        cout << totalColors << endl;
    }

    return 0;
}