#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> perm(n);
    vector<bool> taken(n + 1, false);

    for(int i = 0; i < n; i++) {
        cin >> perm[i];
        if(perm[i] != -1) {
            taken[perm[i]] = true;
        }
    }

    int cnt = n;
    for(int i = 0; i < n; i++) {
        if(perm[i] == -1) {
            while(taken[cnt]) {
                cnt--;
            }
            perm[i] = cnt;
            taken[cnt] = true;
        }
    }

    vector<int> dp(n+1);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        dp[i] = (2LL * dp[i-1] * i) % MOD;
        if(i > 1) {
            dp[i] = (dp[i] + 1LL * (i - 1) * dp[i-2]) % MOD;
        }
    }

    long long ans = 1;
    bool neighbor = false;
    for (int i = 0; i < n; i++) {
        if ((i == 0 || perm[i - 1] != perm[i] - 1 ) && ( i == n - 1 || perm[i + 1] != perm[i] + 1)) {
            if(neighbor) {
                ans = (ans * dp[cnt]) % MOD;
            } else {
                neighbor = true;
            }
            cnt--;
        }
    }

    cout << ans << endl;

    return 0;
}