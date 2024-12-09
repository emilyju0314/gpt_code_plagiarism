#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, q, ans = 0;
bool valid = true;
vector<vector<int>> edges(14);
vector<int> parents(14);

int find(int x) {
    return parents[x] == x ? x : parents[x] = find(parents[x]);
}

void solve(int u) {
    if (u == n + 1) {
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (find(u) != find(i)) {
            int rootU = find(u);
            int rootI = find(i);
            parents[rootU] = rootI;
            solve(u + 1);
            parents[rootU] = rootU;
        }
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (find(a) == find(b) && find(a) != find(c)) {
            valid = false;
        }
        parents[find(a)] = find(c);
    }

    if (!valid) {
        cout << 0 << endl;
        return 0;
    }

    solve(2);
    cout << ans << endl;

    return 0;
}