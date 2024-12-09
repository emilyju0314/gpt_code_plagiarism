#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<int> sortedGrid(n * m + 1);

    // Input grid values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            sortedGrid[grid[i][j]] = i * m + j;
        }
    }

    vector<vector<int>> cycles;

    // Find cycles to sort the grid
    for (int i = 1; i <= n * m; i++) {
        int current = sortedGrid[i];
        int dest = i - 1;

        if (current == dest) {
            continue;
        }

        int destRow = dest / m;
        int destCol = dest % m;
        int currentRow = current / m;
        int currentCol = current % m;

        // Move the current cell to the destination cell
        vector<int> cycle = {4};
        cycle.push_back(grid[destRow][destCol]);
        cycle.push_back(grid[currentRow][currentCol]);
        cycle.push_back(grid[destRow][destCol]);
        cycle.push_back(grid[currentRow][currentCol]);

        if (currentRow != destRow) {
            for (int c = 0; c < m; c++) {
                cycle.push_back(grid[currentRow][c]);
                cycle.push_back(grid[destRow][c]);
            }
        } else {
            for (int r = 0; r < n; r++) {
                cycle.push_back(grid[r][currentCol]);
                cycle.push_back(grid[r][destCol]);
            }
        }

        cycles.push_back(cycle);
    }

    // Output cycles
    cout << cycles.size() << endl;
    for (auto cycle : cycles) {
        for (int i : cycle) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}