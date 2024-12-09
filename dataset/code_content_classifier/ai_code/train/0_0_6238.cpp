#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
bitset<50> museums[MAXN];
bool visited[MAXN];
int in[MAXN], out[MAXN];
int n, m, d;
int timer = 0;

void dfs(int v) {
    visited[v] = true;
    in[v] = timer++;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    out[v] = timer++;
}

int main() {
    cin >> n >> m >> d;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        string schedule;
        cin >> schedule;
        for (int j = 0; j < d; j++) {
            museums[i][j] = (schedule[j] == '1');
        }
    }

    dfs(1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < d; j++) {
            if ((in[i] <= in[1] && out[i] >= out[1]) || ((in[i] < out[1] && out[i] < out[1]) || (in[i] > in[1] && out[i] > in[1]))) {
                ans = max(ans, (museums[1] & museums[i]).count());
            }
        }
    }

    cout << ans << endl;

    return 0;
}