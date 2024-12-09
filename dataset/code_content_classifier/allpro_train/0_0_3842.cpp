#include <iostream>
#include <vector>
using namespace std;

const int mod = 777777777;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> w(3, vector<int>(3));
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cin >> w[i][j];
        }
    }

    vector<int> a(n, 0);
    for(int i=0; i<m; i++) {
        int vi, ti;
        cin >> vi >> ti;
        a[vi-1] = ti;

        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = 1; // initialization

        for(int j=1; j<n; j++) {
            for(int k=0; k<3; k++) {
                for(int l=0; l<3; l++) {
                    if(w[k][l]) {
                        dp[j][l] = (dp[j][l] + dp[j-1][k]) % mod;
                    }
                }
            }
        }

        int ways = 0;
        for(int j=0; j<3; j++) {
            ways = (ways + dp[n-1][j]) % mod;
        }
        cout << ways << endl;
    }

    return 0;
}