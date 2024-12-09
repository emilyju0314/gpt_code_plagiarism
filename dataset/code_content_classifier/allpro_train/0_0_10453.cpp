#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> grid(4, vector<int>(n));
    vector<pair<int, int>> cars(k+1);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) {
                cars[grid[i][j]] = {i, j};
            }
        }
    }

    int moves = 0;
    vector<pair<int, pair<int, int>> sequence;
    for (int i = 1; i <= k; i++) {
        int row = cars[i].first;
        int col = cars[i].second;

        while (row != (i <= n ? 0 : 3)) {
            row += (row < 2 ? 1 : -1);
            // move the car to the neighboring space
            sequence.push_back({i, {row+1, col+1}});
            grid[cars[i].first][cars[i].second] = 0;
            grid[row][col] = i;
            cars[i] = {row, col};
            moves++;

            if (moves > 20000) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << moves << endl;
    for (auto move : sequence) {
        cout << move.first << " " << move.second.first << " " << move.second.second << endl;
    }

    return 0;
}