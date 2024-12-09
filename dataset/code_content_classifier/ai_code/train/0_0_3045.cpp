#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 2e5 + 5;

int n, color[MAXN];
vector<int> adj[MAXN];
int res[MAXN];

int dfs(int v, int p) {
    int w_cnt = (color[v] == 1);
    int b_cnt = (color[v] == 0);
    for(int u : adj[v]) {
        if(u != p) {
            int cnt = dfs(u, v);
            w_cnt += max(0, cnt);
            b_cnt += max(0, -cnt);
        }
    }
    res[v] = w_cnt - b_cnt;
    return w_cnt - b_cnt;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(res, 0, sizeof(res));

    dfs(1, 0);

    for(int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}