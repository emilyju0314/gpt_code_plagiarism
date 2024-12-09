#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;
vector<int> adj[MAXN];
vector<int> depth[MAXN];

int dfs(int u, int p) {
    int max_depth = 0;
    for (int v : adj[u]) {
        if (v != p) {
            int temp = dfs(v, u) + 1;
            max_depth = max(max_depth, temp);
            depth[u].push_back(temp);
        }
    }
    sort(depth[u].begin(), depth[u].end(), greater<int>());
    return max_depth;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        if (depth[i].size() == 0) {
            cout << "0\n";
        } else {
            int dominant_index = depth[i][0];
            for (int j = 1; j < depth[i].size(); j++) {
                if (depth[i][j] < dominant_index) {
                    dominant_index = j;
                    break;
                }
            }
            cout << dominant_index << "\n";
        }
    }

    return 0;
}