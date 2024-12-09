#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int len = dp[n][m];
    int sum = 0;
    while(k > 0) {
        int max_len = -1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(dp[i][j] == len){
                    int count = 1;
                    int x = i-1;
                    int y = j-1;
                    while(dp[x][y]!=0){
                        count++;
                        x--;
                        y--;
                    }
                    if(count > max_len){
                        max_len = count;
                    }
                }
            }
        }
        sum += max_len;
        len--;
        k--;
    }

    cout << sum << endl;

    return 0;
}