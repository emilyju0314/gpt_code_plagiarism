#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> tree[100001];
int parent[100001];
unordered_set<int> forbidden;

void dfs(int node, int par) {
    parent[node] = par;
    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        forbidden.clear();
        for (int i = 1; i <= n; i++) {
            tree[i].clear();
            parent[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            forbidden.insert((b << 10) | c);
        }

        for (int i = 1; i < n; i++) {
            int a = i % n + 1;
            int b = (i + 1) % n + 1;
            if (!forbidden.count((a << 10) | b) && !forbidden.count((b << 10) | a)) {
                tree[a].push_back(b);
                tree[b].push_back(a);
            }
        }

        dfs(1, 0);

        for (int i = 1; i <= n; i++) {
            if (parent[i] != 0) {
                cout << i << " " << parent[i] << endl;
            }
        }
    }

    return 0;
}