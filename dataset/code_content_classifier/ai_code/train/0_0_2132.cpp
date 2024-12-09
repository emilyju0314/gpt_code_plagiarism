#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 20005;

vector<pair<int, char>> adj[MAXN];
string strs[MAXN];
int depth[MAXN];

void dfs(int u, int par, string str) {
    strs[u] = str;
    for (auto v : adj[u]) {
        if (v.first != par) {
            dfs(v.first, u, str + v.second);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int v, u;
        char c;
        cin >> v >> u >> c;
        adj[v].push_back(make_pair(u, c));
        adj[u].push_back(make_pair(v, c));
    }

    dfs(1, -1, "");

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (j != x && j != y && strs[x] > strs[j]) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}