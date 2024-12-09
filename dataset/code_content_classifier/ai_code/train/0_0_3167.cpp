#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<int> colors;

void dfs(int v, int p, int c) {
    int clr = 1;
    for (int u : adj_list[v]) {
        if (u == p) continue;
        while (clr == colors[v] || clr == c) clr++;
        colors[u] = clr++;
    }

    for (int u : adj_list[v]) {
        if (u == p) continue;
        dfs(u, v, colors[v]);
    }
}

int main() {
    int n;
    cin >> n;

    adj_list.resize(n + 1);
    colors.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    colors[1] = 1;
    dfs(1, 0, 0);

    int k = 0;
    for (int i = 1; i <= n; i++) {
        k = max(k, colors[i]);
    }

    cout << k << endl;
    for (int i = 1; i <= n; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;

    return 0;
}