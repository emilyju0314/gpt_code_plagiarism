#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> a;
vector<int> inTime, outTime, timer;
vector<vector<int>> up;

int lca(int u, int v) {
    return inTime[u] < inTime[v] && outTime[u] > outTime[v] ? u : v;
}

int timerCounter = 0;
void dfs(int v, int p) {
    timer[v] = timerCounter++;
    inTime[v] = timer[v];

    up[v][0] = p;
    for (int i = 1; i < up[v].size(); ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }

    outTime[v] = timerCounter++;
}

bool isAncestor(int u, int v) {
    return inTime[u] <= inTime[v] && outTime[u] >= outTime[v];
}

int findAncestor(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    int x = u;
    for (int i = up[u].size() - 1; i >= 0; --i) {
        if (!isAncestor(up[x][i], v)) {
            x = up[x][i];
        }
    }
    return up[x][0];
}

bool isOdd(int start, int end, int c) {
    int count = 0;
    for (int i = start; i != end; i = up[i][0]) {
        if (a[i] == c) {
            count++;
        }
    }
    return count % 2 == 1;
}

int main() {
    int n, q;
    cin >> n >> q;

    a.resize(n);
    adj.resize(n);
    inTime.resize(n);
    outTime.resize(n);
    timer.resize(n);
    up.resize(n, vector<int>(20));

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, 0);

    for (int i = 0; i < q; ++i) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        u--; v--;

        int ancestor = lca(u, v);

        int result = -1;
        if (isAncestor(ancestor, u) && isAncestor(ancestor, v)) {
            result = a[ancestor];
        } else {
            int c = -1;
            for (int j = 0; j < 20; ++j) {
                if (l <= a[up[u][j]] && a[up[u][j]] <= r && !isAncestor(up[u][j], v)) {
                    c = a[up[u][j]];
                    break;
                }
            }
            if (c != -1 && isOdd(u, v, c)) {
                result = c;
            }
        }

        cout << result << endl;
    }

    return 0;
}