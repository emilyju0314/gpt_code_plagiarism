#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<pair<int, int>>> tree;
vector<int> subtree_sizes;
vector<int> subtree_distances;

void dfs(int node, int parent, int distance) {
    subtree_sizes[node] = 1;
    subtree_distances[node] = distance;
    for (auto& neighbor : tree[node]) {
        if (neighbor.first != parent) {
            dfs(neighbor.first, node, distance + neighbor.second);
            subtree_sizes[node] += subtree_sizes[neighbor.first];
        }
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n);
    subtree_sizes.resize(n);
    subtree_distances.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;
        tree[a].push_back({b, l});
        tree[b].push_back({a, l});
    }

    dfs(0, -1, 0);

    long long total_distance = 0;
    for (int i = 0; i < n; i++) {
        total_distance += subtree_distances[i];
    }

    int q;
    cin >> q;

    while (q--) {
        int r, w;
        cin >> r >> w;
        r--;

        total_distance -= (subtree_sizes[tree[r][0].first] > subtree_sizes[tree[r][1].first] ? 
                          2LL * subtree_sizes[tree[r][1].first] * tree[r][1].second:
                          2LL * subtree_sizes[tree[r][0].first] * tree[r][0].second);

        tree[r][2].second = w;
        
        total_distance += 2LL * subtree_sizes[0] * tree[0].second;

        cout << fixed;
        cout.precision(10);
        cout << 1.0 * total_distance / (1LL * n * (n - 1)) << endl;
    }

    return 0;
}