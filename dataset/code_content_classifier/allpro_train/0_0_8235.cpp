#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> cnt0, cnt1;
long long ans = 0;

void dfs(int v, int p) {
    cnt0[v] = 1;
    cnt1[v] = 0;

    for (auto& u : adj[v]) {
        if (u.first == p) continue;

        dfs(u.first, v);

        cnt0[v] += cnt0[u.first];
        cnt1[v] += cnt1[u.first];

        if (u.second == 1) {
            ans += (long long)cnt0[u.first] * (cnt0[v] - cnt0[u.first]);
            ans += (long long)cnt1[u.first] * (cnt1[v] - cnt1[u.first]);
        } else {
            ans += (long long)cnt1[u.first] * (cnt0[v] - cnt0[u.first]);
            ans += (long long)cnt0[u.first] * (cnt1[v] - cnt1[u.first]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    cnt0.resize(n);
    cnt1.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }

    dfs(0, -1);

    cout << ans << endl;

    return 0;
}