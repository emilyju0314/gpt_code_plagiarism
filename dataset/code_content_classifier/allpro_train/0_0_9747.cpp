#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    // Input the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int total_empty_cells = 0;
    int total_steps = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                // Count the number of empty cells
                total_empty_cells++;

                // Calculate the average number of steps for this empty cell
                int steps = 0;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (grid[x][y] == '.' && (x != i || y != j)) {
                            // Calculate the Manhattan distance to the empty cell
                            int distance = abs(x - i) + abs(y - j);
                            steps += distance;
                        }
                    }
                }

                total_steps += steps;
            }
        }
    }

    // Calculate the average lifespan of a particle
    double average_lifespan = double(total_steps) / total_empty_cells;
    cout << fixed;
    cout.precision(12);
    cout << average_lifespan << endl;

    return 0;
}