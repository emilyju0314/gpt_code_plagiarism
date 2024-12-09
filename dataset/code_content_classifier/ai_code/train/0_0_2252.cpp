#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, R, Q;
    cin >> N >> M >> R >> Q;

    vector<pair<int, int>> rules(M);
    for (int i = 0; i < M; i++) {
        cin >> rules[i].first >> rules[i].second >> rules[i].second;
    }

    vector<tuple<int, int, int>> games(Q);
    for (int i = 0; i < Q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        games[i] = make_tuple(x, y, z);
    }

    vector<int> dp(1 << N, 0);
    for (int mask = 0; mask < (1 << N); mask++) {
        int money = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                money++;
            }
        }
        dp[mask] = money * R;
    }

    for (int i = 0; i < Q; i++) {
        int x, y, z;
        tie(x, y, z) = games[i];

        vector<int> new_dp = dp;
        for (int mask = 0; mask < (1 << N); mask++) {
            if ((mask & (1 << (x - 1))) && !(mask & (1 << (y - 1)))) {
                for (auto rule : rules) {
                    int a, b, c;
                    tie(a, b, c) = rule;
                    if ((mask & (1 << a - 1)) && (money >= c)) {
                        new_dp[mask] = max(new_dp[mask], dp[mask] - c + z);
                    }
                }
            }
        }

        dp = new_dp;
    }

    int max_money = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        max_money = max(max_money, dp[mask]);
    }

    cout << max_money << endl;

    return 0;
}