#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const vector<string> digits = {
    "1110111", "0010010", "1011101", "1011011", "0111010",
    "1101011", "1101111", "1010010", "1111111", "1111011"
};

int getRequiredSticks(string& initial, string& final) {
    int diff = 0;
    for (int i = 0; i < 7; i++) {
        if (initial[i] == '1' && final[i] == '0') return -1;
        if (initial[i] == '0' && final[i] == '1') diff++;
    }
    return diff;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> scoreboard(n);
    for (int i = 0; i < n; i++) {
        cin >> scoreboard[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    dp[n][0] = 0;

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            for (int d = 9; d >= 0; d--) {
                int required = getRequiredSticks(scoreboard[i], digits[d]);
                if (required != -1 && j >= required && dp[i+1][j-required] != -1) {
                    dp[i][j] = d;
                    break;
                }
            }
        }
    }

    if (dp[0][k] == -1) {
        cout << -1 << endl;
    } else {
        int remainingSticks = k;
        for (int i = 0; i < n; i++) {
            cout << dp[i][remainingSticks];
            remainingSticks -= getRequiredSticks(scoreboard[i], digits[dp[i][remainingSticks]]);
        }
        cout << endl;
    }

    return 0;
}