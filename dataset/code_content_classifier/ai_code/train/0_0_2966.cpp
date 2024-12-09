#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> grid(n);
        vector<pair<int, int>> asterisks;

        for (int i = 0; i < n; i++) {
            cin >> grid[i];
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    asterisks.push_back({i, j});
                }
            }
        }

        int row1 = asterisks[0].first;
        int col1 = asterisks[0].second;
        int row2 = asterisks[1].first;
        int col2 = asterisks[1].second;

        // Find the other two corners of the rectangle
        if (row1 == row2) {
            if (row1 + 1 < n) {
                grid[row1+1][col1] = '*';
                grid[row1+1][col2] = '*';
            } else {
                grid[row1-1][col1] = '*';
                grid[row1-1][col2] = '*';
            }
        } else if (col1 == col2) {
            if (col1 + 1 < n) {
                grid[row1][col1+1] = '*';
                grid[row2][col1+1] = '*';
            } else {
                grid[row1][col1-1] = '*';
                grid[row2][col1-1] = '*';
            }
        } else {
            grid[row1][col2] = '*';
            grid[row2][col1] = '*';
        }

        // Output the final grid
        for (int i = 0; i < n; i++) {
            cout << grid[i] << endl;
        }
    }

    return 0;
}