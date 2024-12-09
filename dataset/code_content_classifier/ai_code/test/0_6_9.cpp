#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> columns(k);
    for (int i = 0; i < k; i++) {
        cin >> columns[i];
    }

    for (int i = 0; i < k; i++) {
        int col = columns[i];
        int row = 0;

        while (row < n) {
            int direction = grid[row][col - 1];

            if (direction == 1) {
                col++;
            } else if (direction == 2) {
                grid[row][col - 1] = 2;
                break;
            } else { // direction == 3
                col--;
            }

            row++;
        }

        cout << col << " ";
    }

    return 0;
}