#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<bool>> matrix(n, vector<bool>(m, false));
    set<pair<int, int>> locked_cells;

    auto get_staircases = [&]() {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j]) continue;
                if (i > 0 && !matrix[i-1][j]) continue;
                if (j > 0 && !matrix[i][j-1]) continue;
                count++;
            }
        }
        return count;
    };

    auto get_neighbors = [&](int x, int y) {
        vector<pair<int, int>> neighbors;
        if (x > 0) neighbors.push_back({x - 1, y});
        if (x < n - 1) neighbors.push_back({x + 1, y});
        if (y > 0) neighbors.push_back({x, y - 1});
        if (y < m - 1) neighbors.push_back({x, y + 1});
        return neighbors;
    };

    auto update_neighbors = [&](int x, int y) {
        for (const auto& [xx, yy] : get_neighbors(x, y)) {
            if (matrix[xx][yy]) {
                if (locked_cells.count({xx, yy})) {
                    locked_cells.erase({xx, yy});
                } else {
                    locked_cells.insert({xx, yy});
                }
            }
        }
    };

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        if (matrix[x][y]) {
            matrix[x][y] = false;
            update_neighbors(x, y);
        } else {
            matrix[x][y] = true;
            update_neighbors(x, y);
        }

        cout << get_staircases() << endl;
    }

    return 0;
}