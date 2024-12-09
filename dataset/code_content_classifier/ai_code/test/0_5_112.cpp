#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Edge {
    int u, v;
    char c;
};

struct Query {
    int u, v, l, r;
};

vector<vector<int>> adj_list;
vector<Edge> edges;
vector<string> strings;
vector<Query> queries;
vector<int> ans;

vector<int> parent, depth, subtree_size, heavy, head, pos, inv_pos, segtree;
int timer;

int dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    subtree_size[u] = 1;
    int max_size = 0;
    for (int v : adj_list[u]) {
        if (v != p) {
            subtree_size[u] += dfs(v, u, d+1);
            if (subtree_size[v] > max_size) {
                max_size = subtree_size[v];
                heavy[u] = v;
            }
        }
    }
    return subtree_size[u];
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = timer++;
    inv_pos[pos[u]] = u;
    
    if (heavy[u] != -1) {
        decompose(heavy[u], h);
    }
    
    for (int v : adj_list[u]) {
        if (v != parent[u] && v != heavy[u]) {
            decompose(v, v);
        }
    }
}

int build_segtree(int v, int tl, int tr) {
    if (tl == tr) {
        return segtree[v] = 1;
    } else {
        int tm = (tl + tr) / 2;
        return segtree[v] = build_segtree(2*v, tl, tm) + build_segtree(2*v+1, tm+1, tr);
    }
}

int query_segtree(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        return segtree[v];
    }
    
    int tm = (tl + tr) / 2;
    return query_segtree(2*v, tl, tm, l, min(r, tm)) + query_segtree(2*v+1, tm+1, tr, max(l, tm+1), r);
}

void update_segtree(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        segtree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update_segtree(2*v, tl, tm, pos, new_val);
        } else {
            update_segtree(2*v+1, tm+1, tr, pos, new_val);
        }
        segtree[v] = segtree[2*v] + segtree[2*v+1];
    }
}

int lca(int u, int v) {
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        u = parent[head[u]];
    }
    return pos[u] < pos[v] ? u : v;
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

string str(int u, int v) {
    string result = "";
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        result += edges[pos[head[u]].c;
        u = parent[head[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    if (u != v) result += edges[pos[u]+1].c; // Assuming there is a dummy edge at position 0
    return result;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    adj_list.resize(n);
    edges.resize(n);
    parent.resize(n);
    depth.resize(n);
    subtree_size.resize(n);
    heavy.resize(n, -1);
    head.resize(n);
    pos.resize(n);
    inv_pos.resize(n);
    segtree.resize(4*n);
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        u--; v--; // 0-indexing
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        edges[i] = {u, v, c};
    }
    
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        strings.push_back(s);
    }
    
    for (int i = 0; i < q; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        u--; v--; l--; r--; // 0-indexing
        queries.push_back({u, v, l, r});
    }
    
    dfs(0, 0, 0);
    decompose(0, 0);
    build_segtree(1, 0, n-1);
    
    for (auto& q : queries) {
        int u = q.u, v = q.v, l = q.l, r = q.r;
        int total_occurrences = 0;
        for (int j = l; j <= r; j++) {
            string s = strings[j];
            string path = str(u, v);
            for (int k = 0; k < s.size() - path.size() + 1; k++) {
                if (s.substr(k, path.size()) == path) {
                    total_occurrences++;
                }
            }
        }
        ans.push_back(total_occurrences);
    }
    
    for (int a : ans) {
        cout << a << endl;
    }
    
    return 0;
}