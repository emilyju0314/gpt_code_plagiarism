#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p, k;
    cin >> n >> p >> k;

    vector<bool> answered(n+1, false);
    
    int r;
    cin >> r;
    for (int i = 0; i < r; i++) {
        int q;
        cin >> q;
        answered[q] = true;
    }

    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        int q;
        cin >> q;
        answered[q] = true;
    }

    vector<vector<int>> dp(p+1, vector<int>(n+1, 0));

    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            
            for (int l = 1; l <= k; l++) {
                if (j-l >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-l] + answered[j]);
                }
            }
        }
    }

    int max_questions = 0;
    for (int i = 1; i <= n; i++) {
        max_questions = max(max_questions, dp[p][i]);
    }

    cout << max_questions << endl;

    return 0;
}