#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int power(int x, int y) {
    if (y == 0) return 1;
    int res = power(x, y/2);
    res = (res * res) % MOD;
    if (y % 2 == 1) res = (res * x) % MOD;
    return res;
}

int main() {
    int n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    int total_colors = power(k, r * c);

    // count the number of possible color combinations
    vector<int> dp(r, 0);
    dp[0] = 1;
    for (int i = 1; i < r; i++) {
        dp[i] = (dp[i-1] * k) % MOD;
    }

    int ans = 0;
    for (int i = 0; i < r; i++) {
        int r1 = (i + ax - bx) % r;
        int r2 = (r - r1) % r;
        int count = (dp[r1] * dp[r2]) % MOD;
        ans = (ans + count) % MOD;
    }

    cout << (total_colors - ans + MOD) % MOD << endl;

    return 0;
}