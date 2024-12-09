#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
vector<int> adj[MAXN];
int c[MAXN], d[MAXN];

int dfs(int u, int p) {
    int sum = 0;
    for (int v : adj[u]) {
        if (v != p) {
            int x = dfs(v, u);
            sum += min(x, c[v]);
        }
    }
    d[u] = c[u];
    for (int v : adj[u]) {
        if (v != p) {
            d[u] = min(d[u], c[v]);
        }
    }
    return sum + d[u];
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }

    int score = dfs(1, 0);

    cout << score << endl;
    for (int i = 1; i <= N; i++) {
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}