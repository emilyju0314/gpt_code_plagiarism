#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> values(n + 1);
    vector<int> masses(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> values[i] >> masses[i];
    }

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    int q;
    cin >> q;

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int v, w;
            cin >> v >> w;
            values.push_back(v);
            masses.push_back(w);

            for(int i = k; i >= w; i--) {
                for(int j = 1; j <= n; j++) {
                    dp[i][j] = max(dp[i][j], dp[i - w][j - 1] + v);
                }
            }

            n++;
        } else if(type == 2) {
            int idx;
            cin >> idx;

            vector<int> new_dp = dp[k];
            for(int i = masses[idx]; i <= k; i++) {
                for(int j = 1; j <= n; j++) {
                    new_dp[i] = max(new_dp[i], dp[i - masses[idx]][j - 1] + values[idx]);
                }
            }

            dp = move(new_dp);

            values.erase(values.begin() + idx);
            masses.erase(masses.begin() + idx);

            n--;
        } else if(type == 3) {
            int ans = 0;
            for(int i = 0; i <= k; i++) {
                ans = (ans + dp[i][n]) % MOD;
            }

            cout << ans << endl;
        }
    }

    return 0;
}