#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;
    vector<pair<int, int>> trips(N);
    for (int i = 0; i < N; i++) {
        int si, leni, ti;
        cin >> si >> leni >> ti;
        trips[i] = {si, leni};
    }

    bool dp[1 << N][P] = {false};
    pair<int, int> prev[1 << N][P];
    dp[0][0] = true;

    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if ((mask & (1 << i)) == 0) {
                for (int j = 0; j < P; j++) {
                    if (dp[mask][j]) {
                        int avail = 0;
                        for (int k = i + 1; k < N; k++) {
                            if ((mask & (1 << k)) == 0) {
                                avail = k;
                                break;
                            }
                        }
                        bool can_add = true;
                        for (int l = 0; l < avail; l++) {
                            if (trips[i].first <= prev[mask | (1 << i)][j].second + trips[l].second && prev[mask | (1 << i)][j].second + ti <= trips[i].first) {
                                can_add = false;
                                break;
                            }
                        }
                        if (can_add) {
                            dp[mask | (1 << i)][j] = true;
                            prev[mask | (1 << i)][j] = {i, prev[mask][j].second + ti};
                        }
                    }
                }
            }
        }
    }

    if (!dp[(1 << N) - 1][0] && P == 2) {
        for (int mask = 0; mask < (1 << N); mask++) {
            for (int i = 0; i < N; i++) {
                if ((mask & (1 << i)) == 0) {
                    for (int j = 0; j < P; j++) {
                        if (dp[mask][j]) {
                            int avail = 0;
                            for (int k = i + 1; k < N; k++) {
                                if ((mask & (1 << k)) == 0) {
                                    avail = k;
                                    break;
                                }
                            }
                            bool can_add = true;
                            for (int l = 0; l < avail; l++) {
                                if (trips[i].first <= prev[mask | (1 << i)][j].second + trips[l].second && prev[mask | (1 << i)][j].second + ti <= trips[i].first) {
                                    can_add = false;
                                    break;
                                }
                            }
                            if (can_add) {
                                dp[mask | (1 << i)][(j + 1) % P] = true;
                                prev[mask | (1 << i)][(j + 1) % P] = {i, prev[mask][j].second + ti};
                            }
                        }
                    }
                }
            }
        }
    }

    if (!dp[(1 << N) - 1][0]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int mask = (1 << N) - 1, cur = 0;
        vector<pair<int, int>> ans;
        while (mask) {
            ans.push_back({prev[mask][cur].first + 1, prev[mask][cur].second - trips[prev[mask][cur].first].second});
            int next_mask = mask ^ (1 << prev[mask][cur].first);
            cur = prev[mask][cur].second % P;
            mask = next_mask;
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << cur + 1 << " " << ans[i].second + 1 << endl;
            cur = (cur + 1) % P;
        }
    }

    return 0;
}