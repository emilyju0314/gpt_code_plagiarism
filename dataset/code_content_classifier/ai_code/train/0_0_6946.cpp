#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<char>> board(n, vector<char>(n));
        vector<vector<pair<int, int>>> coordinates(10);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                int digit = board[i][j] - '0';
                coordinates[digit].push_back({i, j});
            }
        }

        for (int d = 0; d < 10; d++) {
            int maxArea = 0;

            if (coordinates[d].empty()) {
                cout << "0 ";
                continue;
            }

            int minRow = n, maxRow = 0, minCol = n, maxCol = 0;

            for (auto coord : coordinates[d]) {
                minRow = min(minRow, coord.first);
                maxRow = max(maxRow, coord.first);
                minCol = min(minCol, coord.second);
                maxCol = max(maxCol, coord.second);
            }

            maxArea = max(maxRow - minRow + 1, maxCol - minCol + 1);
            cout << maxArea * maxArea << " ";
        }

        cout << endl;
    }

    return 0;
}