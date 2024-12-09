#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp1(n, vector<int>(n)), dp2(n, vector<int>(n));

    dp1[0][0] = grid[0][0];

    for(int i = 1; i < n; i++) {
        dp1[i][0] = dp1[i-1][0] + grid[i][0];
    }

    for(int j = 1; j < n; j++) {
        dp1[0][j] = dp1[0][j-1] + grid[0][j];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + grid[i][j];
        }
    }

    dp2[n-1][n-1] = grid[n-1][n-1];

    for(int i = n-2; i >= 0 ; i--) {
        dp2[i][n-1] = dp2[i+1][n-1] + grid[i][n-1];
    }

    for(int j = n-2; j >= 0; j--) {
        dp2[n-1][j] = dp2[n-1][j+1] + grid[n-1][j];
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j = n-2; j >= 0; j--) {
            dp2[i][j] = max(dp2[i+1][j], dp2[i][j+1]) + grid[i][j];
        }
    }

    int max_points = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            max_points = max(max_points, dp1[i][j] + dp2[i][j] - grid[i][j]);
        }
    }

    cout << max_points << endl;

    return 0;
}