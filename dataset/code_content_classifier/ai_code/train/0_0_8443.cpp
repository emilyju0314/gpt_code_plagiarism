#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 505;

int n, m;
string grid[MAXN];
int dp[MAXN][MAXN][MAXN];

int countBeautifulPaths(int r1, int c1, int r2, int c2) {
    if(r1 == r2 && c1 == c2) return 1;

    if(r1 > r2 || c1 > c2) return 0;

    if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];

    int ans = 0;

    if(grid[r1][c1] == grid[r2][c2]) {
        ans = (ans + countBeautifulPaths(r1+1, c1, r2-1, c2)) % MOD;
        ans = (ans + countBeautifulPaths(r1, c1+1, r2, c2-1)) % MOD;
        ans = (ans - countBeautifulPaths(r1+1, c1, r2, c2-1) + MOD) % MOD;
        ans = (ans - countBeautifulPaths(r1, c1+1, r2-1, c2) + MOD) % MOD;
    }

    dp[r1][c1][c2] = ans;
    return ans;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << countBeautifulPaths(0, 0, n-1, m-1) << endl;

    return 0;
}