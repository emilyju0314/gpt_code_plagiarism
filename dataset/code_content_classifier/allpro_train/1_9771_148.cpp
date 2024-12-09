#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> e(n);
    vector<int> degree(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        ++degree[--u];
        ++degree[--v];
        e[u].push_back(v);
        e[v].push_back(u);
    }
    string s;
    cin >> s;
    vector<int> color(n);
    for (int i = 0; i < n; ++i)
        color[i] = s[i] == 'B' ? 0 : 1;
    queue<int> que;
    for (int i = 0; i < n; ++i)
        if (degree[i] <= 1 && color[i] == 0)
            que.push(i);
    int rest = n;
    vector<bool> removed(n);
    while (!que.empty()) {
        int u = que.front();
        removed[u] = true;
        --rest;
        que.pop();
        for (int v : e[u])
            if (--degree[v] == 1 && color[v] == 0)
                que.push(v);
    }
    if (rest <= 2) {
        cout << rest << "\n";
        return 0;
    }
    int ans = 2 * rest - 2;
    for (int i = 0; i < n; ++i) {
        if (!removed[i]) {
            color[i] ^= degree[i] % 2;
            ans += color[i];
        }
    }
    vector<int> dis;
    auto bfs = [&](int s) {
        queue<int> que;
        dis.assign(n, -1);
        dis[s] = color[s];
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : e[u]) {
                if (removed[v] || dis[v] != -1)
                    continue;
                dis[v] = dis[u] + color[v];
                que.push(v);
            }
        }
        int t = s;
        for (int i = 0; i < n; ++i)
            if (dis[i] > dis[t])
                t = i;
        return t;
    };
    for (int i = 0; i < n; ++i) {
        if (!removed[i]) {
            int s = bfs(i);
            s = bfs(s);
            cout << ans - 2 * dis[s] << "\n";
            return 0;
        }
    }
    return 0;
}