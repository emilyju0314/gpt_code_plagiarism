#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<bool>> grid(h, vector<bool>(w, false));
    for (int i = 0; i < n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        grid[r1][c1] = true;
        grid[r2][c2] = true;
    }

    vector<int> dp1(h, 0);
    vector<int> dp2(w, 0);
    dp1[0] = dp2[0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!grid[i][j]) {
                dp1[i] = (dp1[i] + dp1[max(i-1, 0)]) % MOD;
                dp2[j] = (dp2[j] + dp2[max(j-1, 0)]) % MOD;
            } else {
                dp1[i] = dp2[j] = 0;
            }
        }
    }

    int total_ways = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int ways = (1LL * dp1[i] * dp2[j]) % MOD;
            total_ways = (total_ways + ways) % MOD;
        }
    }

    cout << total_ways << endl;
    
    return 0;
}