#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 705;

vector<int> adj[MAXN];
int n, m, answer = 0;
bool visited[MAXN] = {false};

void dfs(int v, int start, int len, int cur) {
    if (len == 5) {
        if (cur == start) answer++;
        return;
    }

    visited[v] = true;
    
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, start, len+1, cur);
        }
    }

    visited[v] = false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, i, 1, i);
    }

    cout << answer/10 << endl;

    return 0;
}