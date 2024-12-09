#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(4);
    for(int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    vector<vector<char>> matrix(4, vector<char>(n));
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int j = 0; j < n; j++) {
        for(int k = 1; k <= min(4, n - j); k++) {
            int cost = 0;
            for(int row = 0; row < 4; row++) {
                bool valid = true;
                for(int col = j; col < j + k; col++) {
                    if(matrix[row][col] == '.') {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    cost += a[k-1];
                }
            }
            dp[j + k] = min(dp[j + k], dp[j] + cost);
        }
    }

    cout << dp[n] << endl;

    return 0;
}