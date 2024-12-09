#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int max_dist = 0;

void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& nums, vector<bool>& visited) {
    for (int v : adj[u]) {
        if (v != p) {
            visited[v] = true;
            int new_gcd = gcd(nums[u], nums[v]);
            max_dist = max(max_dist, 1); // dist(x, y) = 1 when x and y are adjacent
            if (new_gcd > 1) {
                max_dist = max(max_dist, 2); // dist(x, y) = 2 when x and y have gcd > 1
            }
            dfs(v, u, adj, nums, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }

    vector<bool> visited(n, false);
    dfs(0, -1, adj, nums, visited);

    cout << max_dist << endl;

    return 0;
}