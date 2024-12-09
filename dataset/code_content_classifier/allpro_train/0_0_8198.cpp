#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, k, n, q;
    cin >> x >> k >> n >> q;

    vector<int> jump_costs(k);
    for (int i = 0; i < k; i++) {
        cin >> jump_costs[i];
    }

    vector<pair<int, int>> special_stones;
    for (int i = 0; i < q; i++) {
        int p, wp;
        cin >> p >> wp;
        special_stones.push_back(make_pair(p, wp));
    }

    sort(special_stones.begin(), special_stones.end());

    vector<long long> dp(x+1, 0);
    for (int i = 1; i <= x; i++) {
        dp[i] = jump_costs[i-1];
    }

    for (const auto& special_stone : special_stones) {
        int p = special_stone.first;
        int wp = special_stone.second;
        for (int i = 1; i <= x; i++) {
            dp[i] += wp;
            if (p >= i && p - i <= k) {
                dp[i] = min(dp[i], dp[p - i] + wp);
            }
        }
    }

    cout << dp[x] << endl;

    return 0;
}