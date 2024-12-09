#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m, k, r, c, ax, ay, bx, by;
    cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;
    
    vector<vector<int>> dp(r, vector<int>(c, 0));
    vector<vector<int>> power(k, vector<int>(r * c, 0));
    
    for (int i = 0; i < k; i++) {
        power[i][0] = 1;
        for (int j = 1; j < r * c; j++) {
            power[i][j] = (power[i][j-1] * 1LL * i) % MOD;
        }
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            dp[i][j] = (power[k][i * c + j] - power[0][i * c + j] + MOD) % MOD;
        }
    }
    
    long long result = 0;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (ax + i - 1 < n && bx + i - 1 < n && ay + j - 1 < m && by + j - 1 < m) {
                result = (result + dp[i][j] * 1LL * dp[r - i - 1][c - j - 1]) % MOD;
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}