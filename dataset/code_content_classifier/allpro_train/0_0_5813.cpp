#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> adj;
vector<int> mex;

void dfs(int u, int parent, vector<int>& path) {
    path.push_back(u);

    for (int v : adj[u]) {
        if (v != parent) {
            unordered_set<int> seen(path.begin(), path.end());
            for (int p : path) {
                for (int q : adj[v]) {
                    seen.insert(mex[p * adj.size() + q]);
                }
            }

            mex[u * adj.size() + v] = 0;
            while (seen.count(mex[u * adj.size() + v])) {
                mex[u * adj.size() + v]++;
            }

            dfs(v, u, path);
        }
    }

    path.pop_back();
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    mex.resize(n * n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        vector<int> path;
        dfs(i, -1, path);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += mex[i * adj.size() + j];
        }
    }

    cout << ans << endl;

    return 0;
}