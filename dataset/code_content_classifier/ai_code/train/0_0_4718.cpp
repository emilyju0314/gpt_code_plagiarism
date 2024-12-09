#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

int n;
vector<pair<int, int>> adj[MAX_N];
int leafDist[MAX_N];
int q, l[MAX_N], ans[MAX_N];
int maxChildren;

void dfs(int u, int p, int dist) {
    bool isLeaf = true;
    for (pair<int, int> edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p) {
            isLeaf = false;
            dfs(v, u, dist + w);
        }
    }
    if (isLeaf) {
        leafDist[u] = dist;
    }
}

bool check(int numChildren, int timeBound) {
    int cnt = 1;
    int maxDist = 0;
    for (int i = 2; i <= n; i++) {
        if (leafDist[i] <= timeBound) {
            maxDist = max(maxDist, leafDist[i]);
        }
        else {
            cnt++;
            maxDist = max(maxDist, leafDist[i]);
        }
    }
    return (cnt <= numChildren && maxDist - leafDist[1] <= timeBound);
}

int binarySearch(int timeBound) {
    int l = 1, r = maxChildren;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, timeBound)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        adj[x].push_back({y, v});
        adj[y].push_back({x, v});
    }

    dfs(1, 1, 0);

    for (int i = 1; i <= n; i++) {
        if (leafDist[i] > leafDist[maxChildren]) {
            maxChildren = i;
        }
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> l[i];
    }

    for (int i = 0; i < q; i++) {
        ans[i] = binarySearch(l[i]);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}