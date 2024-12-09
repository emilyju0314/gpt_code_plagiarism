#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin.ignore(); // ignore the blank line

        int n, m;
        cin >> n >> m;

        vector<vector<char>> board(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        unordered_map<char, pair<int, int>> moves = {
            {'L', {0, -1}},
            {'R', {0, 1}},
            {'U', {-1, 0}},
            {'D', {1, 0}}
        };

        int max_steps = 0, start_row, start_col;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int steps = 0, r = i, c = j;
                vector<vector<bool>> visited(n, vector<bool>(m, false));

                while (true) {
                    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c]) {
                        break;
                    } else {
                        visited[r][c] = true;
                        char direction = board[r][c];
                        pair<int, int> move = moves[direction];
                        r += move.first;
                        c += move.second;
                        steps++;
                    }
                }

                if (steps > max_steps) {
                    max_steps = steps;
                    start_row = i + 1;
                    start_col = j + 1;
                }
            }
        }

        cout << start_row << " " << start_col << " " << max_steps << endl;
    }

    return 0;
}