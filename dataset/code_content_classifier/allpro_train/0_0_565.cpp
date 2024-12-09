#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    string pokeBlock;
    cin >> n >> pokeBlock;

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum = (sum * 2 + (pokeBlock[j] - '0')) % MOD;
            dp[i+1][j+1] = sum;
        }
    }

    vector<vector<int>> f(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) {
        f[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 1; k < j; k++) {
                if (dp[k+1][j] >= i) {
                    f[i][j] += f[i-1][k];
                    f[i][j] %= MOD;
                }
            }
        }
    }

    int totalSets = 0;
    for (int i = 1; i <= n; i++) {
        totalSets += f[i][n];
        totalSets %= MOD;
    }

    cout << totalSets << endl;

    return 0;
}