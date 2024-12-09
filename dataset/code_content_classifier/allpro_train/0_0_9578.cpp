#include <iostream>
#include <vector>

using namespace std;

int n, k;

// Define the directions for moving to neighboring cells
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

// Depth-first search to find the size of the connected component starting from cell (r, c)
int dfs(vector<vector<bool>>& visited, vector<string>& grid, int r, int c) {
    int size = 0;
    visited[r][c] = true;
    size++;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] == '.') {
            size += dfs(visited, grid, nr, nc);
        }
    }

    return size;
}

int main() {
    cin >> n >> k;
    vector<string> grid(n);
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int maxComponentSize = 0;

    // Try all possible ranges for Limak
    for (int r = 0; r <= n - k; r++) {
        for (int c = 0; c <= n - k; c++) {
            // Transform blocked cells in the current range to empty ones
            for (int i = r; i < r + k; i++) {
                for (int j = c; j < c + k; j++) {
                    if (grid[i][j] == 'X') {
                        grid[i][j] = '.';
                        // Reset visited array for each new range
                        visited = vector<vector<bool>(n, vector<bool>(n, false));
                    }
                }
            }

            // Find the size of the largest connected component
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '.' && !visited[i][j]) {
                        int componentSize = dfs(visited, grid, i, j);
                        if (componentSize > maxComponentSize) {
                            maxComponentSize = componentSize;
                        }
                    }
                }
            }

            // Restore blocked cells in the current range 
            for (int i = r; i < r + k; i++) {
                for (int j = c; j < c + k; j++) {
                    if (grid[i][j] == '.') {
                        grid[i][j] = 'X';
                    }
                }
            }
        }
    }

    cout << maxComponentSize << endl;

    return 0;
}