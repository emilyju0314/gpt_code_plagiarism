#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;
    
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    
    vector<vector<int>> dp(r+1, vector<int>(c+1, 0));
    dp[0][0] = 1; // Initial case
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int add = (1LL * dp[i][j] * k) % MOD;
            dp[i+1][j] = (dp[i+1][j] + add) % MOD;
            dp[i][j+1] = (dp[i][j+1] + add) % MOD;
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int diffx = bx - ax - i;
            int diffy = by - ay - j;
            
            long long add = 1LL * dp[i][j] * dp[r-1-i][c-1-j] % MOD;
            add = (add * k) % MOD;
            add = (add * k) % MOD;
            add = (add * diffx) % MOD;
            add = (add * diffy) % MOD;
            ans = (ans + add) % MOD;
        }
    }
    
    cout << ans << endl;

    return 0;
}