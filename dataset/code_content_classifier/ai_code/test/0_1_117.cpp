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

        // Input the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }

        // Find the cell with the lab
        int lab_row, lab_col;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L') {
                    lab_row = i;
                    lab_col = j;
                    break;
                }
            }
        }

        // Mark cells that can reach the lab
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    if ((i == lab_row || j == lab_col) || (i != lab_row && j != lab_col)) {
                        grid[i][j] = '+';
                    }
                }
            }
        }

        // Output the modified grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << grid[i][j];
            cout << endl;
        }
    }

    return 0;
}