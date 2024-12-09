#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int n, k;
vector<int> students;

int dp[201][1001][201];

int solve(int idx, int total_imbalance, int min_time) {
    if (idx == n) {
        if (total_imbalance <= k) return 1;
        else return 0;
    }
    
    if (dp[idx][total_imbalance][min_time] != -1) {
        return dp[idx][total_imbalance][min_time];
    }

    int ans = solve(idx+1, total_imbalance, min(students[idx], min_time));
    ans = (ans + solve(idx+1, total_imbalance + max(students[idx] - min_time, 0), min_time)) % MOD;

    return dp[idx][total_imbalance][min_time] = ans;
}

int main() {
    cin >> n >> k;
    students.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 0, 500);
    cout << ans << endl;

    return 0;
}