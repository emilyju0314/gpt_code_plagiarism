#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 25005;

int n, q;
int a[MAXN];
vector<pair<int, int>> intervals;
int dp[MAXN];
int sorted[MAXN];
int bit[MAXN];

void update(int idx, int val) {
    while(idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int result = 0;
    while(idx > 0) {
        result += bit[idx];
        idx -= idx & -idx;
    }
    return result;
}

void solve() {
    memset(bit, 0, sizeof(bit));
    memset(dp, 0, sizeof(dp));

    for (auto [l, r] : intervals) {
        update(l, 1);
        update(r + 1, -1);
    }

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);
    sort(perm.begin(), perm.end(), [](int i, int j) {
        return a[i - 1] < a[j - 1];
    });

    for (int i = 0; i < n; i++) {
        sorted[perm[i]] = i + 1;
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + (query(sorted[i]) > 0);
    }
}

int main() {
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        intervals.push_back({l, r});
    }

    solve();

    for (int i = 1; i <= q; i++) {
        cout << dp[i] << endl;
    }

    return 0;
}