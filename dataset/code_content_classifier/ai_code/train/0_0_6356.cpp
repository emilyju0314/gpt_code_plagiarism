#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> gym(n, vector<int>(m));
    vector<vector<int>> dp1(n, vector<int>(m));
    vector<vector<int>> dp2(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> gym[i][j];
            dp1[i][j] = gym[i][j];
            dp2[i][j] = gym[i][j];
        }
    }

    // Calculate maximum total gain for Iahub moving down and right
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp1[i][j] += max(dp1[i - 1][j], dp1[i][j - 1]);
        }
    }

    // Calculate maximum total gain for Iahubina moving up and right
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 1; j < m; j++) {
            dp2[i][j] += max(dp2[i + 1][j], dp2[i][j - 1]);
        }
    }

    int maxGain = 0;

    // Find the maximum total gain when Iahub and Iahubina meet at each cell
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            maxGain = max(maxGain, dp1[i][j-1] + dp2[i+1][j]);
        }
    }

    cout << maxGain << endl;

    return 0;
}