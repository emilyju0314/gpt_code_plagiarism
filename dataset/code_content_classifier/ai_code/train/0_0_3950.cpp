#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(4*m+1, 0));
    vector<string> carpet(4*n+1);

    for(int i=0; i<4*n+1; i++)
        cin >> carpet[i];
    
    dp[0][0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int mask = 0;
            for(int k=0; k<3; k++) {
                for(int l=0; l<3; l++) {
                    if(carpet[4*i+k][4*j+l] == 'O')
                        mask |= 1 << (3*k+l);
                }
            }

            for(int k=0; k<4*m; k++) {
                if(dp[i][k] == 0) continue;
                if(k%4 == 0) {
                    int new_mask = mask;
                    bool possible = true;
                    for(int l=0; l<4; l++) {
                        if((new_mask & (1 << l)) && (k+l >= 4*m || (k+l)%4 == 3 || (mask & (1 << (l+1))))) {
                            possible = false;
                            break;
                        }
                        new_mask |= 1 << l;
                    }
                    if(possible)
                        dp[i+1][k+4] = (dp[i+1][k+4] + dp[i][k]) % MOD;
                }

                if(k+3 < 4*m && (mask & (1 << 3))) {
                    bool possible = true;
                    for(int l=0; l<4; l++) {
                        if((k+l >= 4*m || (k+l)%4 == 3 || (mask & (1 << l)))) {
                            possible = false;
                            break;
                        }
                    }
                    if(possible)
                        dp[i+1][k+4] = (dp[i+1][k+4] + dp[i][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int k=0; k<4*m+1; k++)
        ans = (ans + dp[n][k]) % MOD;

    cout << ans << endl;

    return 0;
}