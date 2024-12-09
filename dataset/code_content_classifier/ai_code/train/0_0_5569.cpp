#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 50005;
vector<int> adj[MAXN];
int dist[MAXN];
int cnt;

void dfs(int v, int p, int d, int k) {
    dist[v] = d;
    if (d == k) {
        cnt++;
    }

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d+1, k);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        dfs(i, -1, 0, k);
        ans += cnt;
    }

    cout << ans / 2 << endl;

    return 0;
}