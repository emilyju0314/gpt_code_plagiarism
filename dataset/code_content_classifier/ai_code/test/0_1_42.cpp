#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

struct FenwickTree {
    vector<int> bit;

    FenwickTree(int n) {
        bit.assign(n + 1, 0);
    }

    int sum(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
            if (res >= MOD) res -= MOD;
        }
        return res;
    }

    void add(int idx, int delta) {
        for (; idx < bit.size(); idx += idx & -idx) {
            bit[idx] += delta;
            if (bit[idx] >= MOD) bit[idx] -= MOD;
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end());

    int t;
    cin >> t;
    vector<int> funnySet(t);
    for (int i = 0; i < t; i++) {
        cin >> funnySet[i];
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    FenwickTree ft(2*n);
    int funnyMask = 0;
    int timeTravels = 0;

    for (int i = 0; i < n; i++) {
        int taskIdx = lower_bound(funnySet.begin(), funnySet.end(), tasks[i].second) - funnySet.begin();
        if (taskIdx < t && funnySet[taskIdx] == tasks[i].second) {
            funnyMask |= (1 << taskIdx);
        }

        if (funnyMask == (1 << t) - 1) {
            timeTravels = ft.sum(tasks[i].second - 1);
            break;
        }

        dp[i + 1] = ft.sum(tasks[i].second - 1);
        ft.add(tasks[i].second, dp[i + 1]);
    }

    cout << timeTravels << endl;

    return 0;
}