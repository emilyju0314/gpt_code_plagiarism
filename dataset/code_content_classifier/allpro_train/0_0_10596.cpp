#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<int> adj[MAXN];
vector<int> operations[MAXN];
set<int> lists[MAXN];

vector<int> ans(MAXN, 0);

void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            set<int> intersect;
            set_intersection(lists[u].begin(), lists[u].end(), lists[v].begin(), lists[v].end(), inserter(intersect, intersect.begin()));
            ans[u] += intersect.size();
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        operations[a].push_back(i);
        operations[b].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int op : operations[i]) {
            lists[i].insert(op);
        }
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}