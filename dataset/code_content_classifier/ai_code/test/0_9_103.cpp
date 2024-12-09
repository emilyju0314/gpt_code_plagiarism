#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> board(n);
        for (int i = 0; i < n; i++) {
            cin >> board[i];
        }

        int max_distance = 0;
        int start_row = 1, start_col = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r = i, c = j, distance = 0;
                vector<vector<bool>> visited(n, vector<bool>(m, false));

                while (true) {
                    if (r < 0 || r >= n || c < 0 || c >= m) {
                        break;
                    }

                    if (visited[r][c]) {
                        break;
                    }

                    visited[r][c] = true;

                    char direction = board[r][c];
                    if (direction == 'L') {
                        c--;
                    } else if (direction == 'R') {
                        c++;
                    } else if (direction == 'D') {
                        r++;
                    } else if (direction == 'U') {
                        r--;
                    }

                    distance++;
                }

                if (distance > max_distance) {
                    max_distance = distance;
                    start_row = i + 1;
                    start_col = j + 1;
                }
            }
        }

        cout << start_row << " " << start_col << " " << max_distance << endl;
    }

    return 0;
}