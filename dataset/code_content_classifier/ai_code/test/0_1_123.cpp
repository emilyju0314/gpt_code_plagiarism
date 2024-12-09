#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> white, red, blue;

void dfs(int u, int parent) {
    white[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            white[u] += white[v];
            red[u] += red[v];
            blue[u] += blue[v];
        }
    }
    
    if (red[u] + 1 <= white[u]) {
        red[u]++;
        white[u]--;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    adj.resize(n + 1);
    white.resize(n + 1, 0);
    red.resize(n + 1, 0);
    blue.resize(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    long long score = 0;
    for (int i = 1; i <= n; i++) {
        score += white[i] * (red[i] - blue[i]);
    }

    cout << score << endl;

    return 0;
}