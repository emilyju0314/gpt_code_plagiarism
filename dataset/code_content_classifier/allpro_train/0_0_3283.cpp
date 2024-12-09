#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int N;
vector<vector<int>> cost;
vector<int> dp;

int solve(int bitmask) {
    if (bitmask == (1 << N) - 1) return 0; // all numbers are sorted

    int& ret = dp[bitmask];
    if (ret != -1) return ret;

    ret = -INF;
    for (int i = 0; i < N; i++) {
        if (!(bitmask & (1 << i))) {
            for (int j = i + 1; j < N; j++) {
                if (!(bitmask & (1 << j))) {
                    ret = max(ret, solve(bitmask | (1 << i) | (1 << j)) + cost[i][j]);
                }
            }
        }
    }
    return ret;
}

int main() {
    cin >> N;
    cost.resize(N, vector<int>(N));
    dp.assign(1 << N, -1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    int max_cost = solve(0);
    cout << max_cost << endl;

    return 0;
}