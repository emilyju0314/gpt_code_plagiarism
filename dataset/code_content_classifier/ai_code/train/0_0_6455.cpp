#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<vector<char>> grid;
vector<pair<int, int>> water_cells;

int count_lakes(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '*' || grid[i][j] == 'X') {
        return 0;
    }

    grid[i][j] = 'X';
    return 1 + count_lakes(i+1, j) + count_lakes(i-1, j) + count_lakes(i, j+1) + count_lakes(i, j-1);
}

int main() {
    cin >> n >> m >> k;

    grid.resize(n, vector<char>(m));
    water_cells.clear();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') {
                water_cells.push_back({i, j});
            }
        }
    }

    int lakes = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                int lake_size = count_lakes(i, j);
                if (lake_size > 1) {
                    lakes++;
                }
            }
        }
    }

    sort(water_cells.begin(), water_cells.end(), [&](pair<int, int>& a, pair<int, int>& b) {
        int adj_water_a = 0;
        int adj_water_b = 0;
        
        for (int i = 0; i < 4; i++) {
            int new_i = a.first + (i == 0) - (i == 1);
            int new_j = a.second + (i == 2) - (i == 3);
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == '.') {
                adj_water_a++;
            }

            new_i = b.first + (i == 0) - (i == 1);
            new_j = b.second + (i == 2) - (i == 3);
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == '.') {
                adj_water_b++;
            }
        }

        return adj_water_a < adj_water_b;
    });

    int cells_to_transform = lakes - k;
    for (int i = 0; i < cells_to_transform; i++) {
        int row = water_cells[i].first;
        int col = water_cells[i].second;
        grid[row][col] = '*';
    }

    cout << cells_to_transform << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}