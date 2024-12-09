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

        string commands;
        cin >> commands;

        vector<int> dx = {0, 0, 1, -1}; // Movement in x direction (Right, Left, Down, Up)
        vector<int> dy = {1, -1, 0, 0}; // Movement in y direction

        int maxCommands = 0;
        pair<int, int> startCell;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x = i, y = j;
                int count = 0;

                for (char c : commands) {
                    if (c == 'R') x += dx[0];
                    else if (c == 'L') x += dx[1];
                    else if (c == 'D') y += dy[2];
                    else if (c == 'U') y += dy[3];

                    if (x < 1 || x > n || y < 1 || y > m) break; // Robot fell off the board
                    count++;
                }

                if (count > maxCommands) {
                    maxCommands = count;
                    startCell = make_pair(i, j);
                }
            }
        }

        cout << startCell.first << " " << startCell.second << endl;
    }

    return 0;
}