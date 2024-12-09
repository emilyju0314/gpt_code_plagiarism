#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

#define MOD 1000000007

int main() {
    int n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    vector<vector<int>> dp(r, vector<int>(c, 0));
    unordered_set<long long> hashset;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            hashset.insert((long long)i * m + j);
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            dp[i][j] = k;
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(hashset.count((long long)i * m + j)) {
                dp[i][j] = k - 1;
            }
        }
    }

    int ans = 1;
    for(int i = ax; i <= ax+r-1; i++) {
        for(int j = ay; j <= ay+c-1; j++) {
            ans = (1LL * ans * dp[(i-bx+r)%r][(j-by+c)%c]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}