#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 250005;
const int MAXK = 30;
const int MOD = 1000000007;

int n, k, p;
int dp[MAXN][1 << MAXK];

int solve(int remaining, int mask) {
    if (remaining == 0) return 1; // Alice wins if Bob has no moves left
    
    int& res = dp[remaining][mask];
    if (res != -1) return res;
    
    res = 0;
    for (int i = 0; i < k; i++) {
        if ((mask & (1 << i)) == 0) {
            // If character i is not used yet, Alice can delete it
            if (solve(remaining - 1, mask | (1 << i))) {
                res = (res + solve(remaining - 1, mask | (1 << i))) % p;
            }
        } else {
            // If character i is already used, Alice can permute it
            res = (res + solve(remaining - 1, mask)) % p;
        }
    }
    
    return res;
}

int main() {
    cin >> n >> k >> p;
    
    memset(dp, -1, sizeof(dp));
    
    int ans = solve(n, 0);
    cout << ans << endl;
    
    return 0;
}