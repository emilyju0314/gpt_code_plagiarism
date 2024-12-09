#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define MOD 1000000009
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> sequences(m);
    for(int i = 0; i < m; i++) {
        cin >> sequences[i];
    }

    int dp[1001];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            int len = sequences[j].size();
            if(i - len >= 0) {
                bool valid = true;
                for(int k = 0; k < len; k++) {
                    if(sequences[j][k] != 'A' && sequences[j][k] != 'C' && sequences[j][k] != 'G' && sequences[j][k] != 'T') {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    string substr = sequences[j];
                    int subsequences = 1;
                    for(int k = i - len + 1; k <= i; k++) {
                        if(dp[k-1] != 0) {
                            subsequences = subsequences % MOD + dp[k - 1] % MOD;
                        }
                    }
                    dp[i] = (dp[i] + subsequences % MOD) % MOD;
                }
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}