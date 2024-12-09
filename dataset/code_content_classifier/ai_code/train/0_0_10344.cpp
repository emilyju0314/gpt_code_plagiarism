#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for(int i=0; i<m; i++) {
        cin >> b[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1)); // initialize dp array with -1

    dp[0][0] = 0; // base case
    
    int maxDollars = 0; // variable to store the maximum number of dollars Sereja can earn

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i > 0 && j > 0 && dp[i-1][j-1] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1); // first action
                if(i + j > 1) {
                    int energy = i*e + j*e;
                    if(energy <= s) {
                        maxDollars = max(maxDollars, dp[i][j]);
                    } 
                }
            }
            if(i > 0 && dp[i-1][j] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]); // remove elements from sequence a
            }
            if(j > 0 && dp[i][j-1] != -1) {
                dp[i][j] = max(dp[i][j], dp[i][j-1]); // remove elements from sequence b
            }
        }
    }

    cout << maxDollars << endl;

    return 0;
}