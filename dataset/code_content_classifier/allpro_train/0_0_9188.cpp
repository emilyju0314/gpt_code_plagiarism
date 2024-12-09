#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
vector<int> depth;
vector<int> ancestor;
vector<int> component_id;
vector<int> component_size;
map<pair<int, int>, int> edge_states;

int find_set(int v) {
    if (v != parent[v]) {
        parent[v] = find_set(parent[v]);
    }
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (depth[a] < depth[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if (depth[a] == depth[b]) {
            depth[a]++;
        }
    }
}

void dfs(int v, int p, int d) {
    visited[v] = true;
    parent[v] = v;
    ancestor[v] = v;
    depth[v] = d;

    for (int u : adj[v]) {
        if (u == p) continue;
        if (!visited[u]) {
            dfs(u, v, d + 1);
            union_sets(v, u);
            ancestor[find_set(v)] = v;
        }
    }

    for (int u : adj[v]) {
        if (u != p && visited[u]) {
            component_size[find_set(v)]++;
        }
    }
}

int lca(int a, int b) {
    while (find_set(a) != find_set(b)) {
        if (depth[find_set(a)] < depth[find_set(b)]) {
            swap(a, b);
        }
        a = ancestor[find_set(a)];
    }
    return a;
}

void update_edge_states(int a, int b) {
    int l = lca(a, b);
    while (a != l) {
        edge_states[{a, parent[a]}] ^= 1;
        a = parent[a];
    }
    while (b != l) {
        edge_states[{b, parent[b]}] ^= 1;
        b = parent[b];
    }
}

int count_components() {
    int num_components = 0;

    for (const auto& [edge, state] : edge_states) {
        int a = edge.first;
        int b = edge.second;

        int set_a = find_set(a);
        int set_b = find_set(b);

        if (state == 1 && set_a != set_b) {
            num_components++;
        }
    }

    return num_components + component_id.size();
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited.assign(n, false);
    parent.resize(n);
    depth.resize(n);
    ancestor.resize(n);
    component_size.assign(n, 1);
    dfs(0, -1, 0);

    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;

        update_edge_states(v, u);

        cout << count_components() << endl;
    }

    return 0;
}