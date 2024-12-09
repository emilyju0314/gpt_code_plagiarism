#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> candies(n);
    vector<int> stones(m);

    for (int i = 0; i < n; i++) {
        cin >> candies[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> stones[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            dp[i][j] = max((candies[i] + stones[j]) % p + dp[i+1][j], (candies[i] + stones[j]) % p + dp[i][j+1]);
        }
    }

    int i = 0, j = 0;
    string moves = "";

    while (i < n-1 || j < m-1) {
        if ((candies[i] + stones[j])%p + dp[i+1][j] >= (candies[i] + stones[j])%p + dp[i][j+1]) {
            moves += "C";
            i++;
        } else {
            moves += "S";
            j++;
        }
    }

    cout << dp[0][0] << endl;
    cout << moves << endl;

    return 0;
}