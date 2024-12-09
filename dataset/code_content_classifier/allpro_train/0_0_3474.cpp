#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input;
    cin >> input;

    int n = input.length();

    vector<vector<int>> dp(10, vector<int>(10, 0));

    // Initialize the dp matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = n - 1;
        }
    }

    // Fill in the dp matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < n - 1; k++) {
                int next_digit = (input[k] - '0' + i) % 10;
                if (dp[i][j] + (j != (input[k + 1] - '0')) < dp[next_digit][j]) {
                    dp[next_digit][j] = dp[i][j] + (j != (input[k + 1] - '0'));
                }
            }
        }
    }

    // Output the dp matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (dp[i][j] == n - 1) {
                cout << "-1 ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}