#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> tree;
vector<pair<int, int>> colors;
vector<int> max_colorfulness;

void dfs(int node, int parent) {
    unordered_map<int, int> freq;
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
            freq[max_colorfulness[child]]++;
        }
    }
    max_colorfulness[node] = freq.size() + (colors[node - 1].first != colors[node - 1].second);
}

int main() {
    int N, K;
    cin >> N >> K;

    tree.resize(N + 1);
    colors.resize(N);
    max_colorfulness.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for (int i = 0; i < N; i++) {
        cin >> colors[i].first >> colors[i].second;
    }

    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        cout << max_colorfulness[i] << endl;
    }

    return 0;
}