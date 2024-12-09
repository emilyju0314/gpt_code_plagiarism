#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

vector<int> parent;
vector<int> depth;
vector<vector<int>> adj_list;

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (depth[x] < depth[y]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        if (depth[x] == depth[y]) {
            depth[x]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n+1);
    depth.resize(n+1, 0);
    adj_list.resize(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int xi, yi;
        cin >> xi >> yi;

        vector<int> num_paths(n+1, 0);
        num_paths[xi] = 1;

        for (int j = 1; j <= n; j++) {
            for (int u : adj_list[j]) {
                if (find(j) == find(xi) && find(u) == find(yi)) {
                    num_paths[u] = (num_paths[u] + num_paths[j]) % MOD;
                }
            }
        }

        cout << num_paths[yi] << endl;
    }

    return 0;
}