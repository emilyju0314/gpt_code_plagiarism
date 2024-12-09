#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> grid(n, vector<char>(m));
        int labRow, labCol;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'L') {
                    labRow = i;
                    labCol = j;
                }
            }
        }

        vector<vector<bool>> reachable(n, vector<bool>(m, false));

        if (labRow > 0) {
            reachable[labRow - 1][labCol] = true;
        }
        if (labRow < n - 1) {
            reachable[labRow + 1][labCol] = true;
        }
        if (labCol > 0) {
            reachable[labRow][labCol - 1] = true;
        }
        if (labCol < m - 1) {
            reachable[labRow][labCol + 1] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.' && reachable[i][j]) {
                    grid[i][j] = '+';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}