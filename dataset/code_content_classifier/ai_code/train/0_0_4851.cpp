#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;
vector<pair<int, long long>> adj[MAXN];
int n, k;

long long dfs(int u, int p, long long xr) {
    long long res = 0;
    for (auto edge : adj[u]) {
        int v = edge.first;
        long long w = edge.second;
        if (v != p) {
            res = max(res, dfs(v, u, xr ^ w));
        }
    }
    res = max(res, xr);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int p;
        long long w;
        cin >> p >> w;
        adj[p].push_back({i + 1, w});
        adj[i + 1].push_back({p, w});
    }

    long long ans = dfs(1, 0, 0);
    long long ans2 = 0;

    vector<long long> nums;
    while (ans > 0) {
        nums.push_back(ans % 2);
        ans /= 2;
    }

    while (k > 1) {
        if (nums.empty()) {
            cout << 0 << endl;
            return 0;
        }
        if (nums.back() == 1) {
            k--;
        }
        nums.pop_back();
    }

    for (int i = 0; i < nums.size(); i++) {
        ans2 += nums[i] * (1 << i);
    }

    cout << ans2 << endl;

    return 0;
}