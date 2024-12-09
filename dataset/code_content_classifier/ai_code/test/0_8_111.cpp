#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 998244353;

int n, k;
vector<int> b;
int dp[2005][405][2];
int pref[2005][405][2];

int solve(int idx, int val, bool can_be_zero) {
    if(idx == n) {
        return val >= 0 && val <= n ? 1 : 0;
    }

    int &res = dp[idx][val][can_be_zero];
    int &pre = pref[idx][val][can_be_zero];
    if(pre != -1) {
        return res;
    }

    pre = 0;
    res = 0;
    for(int i = 0; i <= n; i++) {
        if(abs(val - b[idx]) <= k || i == 0) {
            if(i == 0 && !can_be_zero) {
                continue;
            }
            res += solve(idx + 1, i, can_be_zero || i > 0);
            if(res >= MOD) {
                res -= MOD;
            }
        }
    }

    pre = 1;
    return res;
}

int main() {
    cin >> n >> k;
    b.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    memset(dp, -1, sizeof(dp));
    memset(pref, -1, sizeof(pref));

    int ans = solve(0, 0, false);
    cout << ans << endl;

    return 0;
}