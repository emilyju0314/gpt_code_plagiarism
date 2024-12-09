#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> white, red, blue;
int k;

void dfs(int u, int parent) {
    white[u] = 1;
    for(int v : adj[u]) {
        if(v != parent) {
            dfs(v, u);
            white[u] += white[v];
            red[u] += min(red[v], k);
            blue[u] += min(blue[v], k);
        }
    }
    red[u] = min(red[u] + 1, white[u]);
}

int main() {
    int n;
    cin >> n >> k;

    adj.resize(n + 1);
    white.resize(n + 1, 0);
    red.resize(n + 1, 0);
    blue.resize(n + 1, 0);

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    long long result = 0;
    for(int i = 1; i <= n; i++) {
        result += white[i] * (red[i] - blue[i]);
    }

    cout << result << endl;

    return 0;
}