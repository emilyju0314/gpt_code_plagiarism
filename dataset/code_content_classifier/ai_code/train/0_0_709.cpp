#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
int subtree_size[100001];

void dfs(int node, int parent) {
    subtree_size[node] = 1;
    for(int child: tree[node]) {
        if(child != parent) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }
    }
}

int find_centroid(int node, int parent, int n) {
    for(int child: tree[node]) {
        if(child != parent && subtree_size[child] > n/2) {
            return find_centroid(child, node, n);
        }
    }
    return node;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        tree[i].clear();
    }

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    int centroid = find_centroid(1, 0, n);

    int child = -1;
    for(int adj: tree[centroid]) {
        if(subtree_size[adj] == n/2) {
            child = adj;
            break;
        }
    }

    if(child == -1) {
        cout << "1 " << tree[centroid][0] << endl;
        cout << "1 " << tree[centroid][0] << endl;
    } else {
        cout << centroid << " " << child << endl;
        cout << centroid << " " << tree[centroid][0] << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}