#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int r, c, k;
        cin >> r >> c >> k;

        vector<pair<int, pair<int, int>>> rice_cells;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char cell;
                cin >> cell;
                if (cell == 'R') {
                    rice_cells.push_back(make_pair(0, make_pair(i, j));
                }
            }
        }

        for (int i = 0; i < rice_cells.size(); i++) {
            int x = rice_cells[i].second.first;
            int y = rice_cells[i].second.second;
            rice_cells[i].first = x * c + y;
        }

        sort(rice_cells.begin(), rice_cells.end(), greater<pair<int, pair<int, int>>>());

        char chicken = '0';
        for (int i = 0; i < rice_cells.size(); i++) {
            if (i % k == 0) {
                chicken++;
            }
            int x = rice_cells[i].second.first;
            int y = rice_cells[i].second.second;
            grid[x][y] = chicken;
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}