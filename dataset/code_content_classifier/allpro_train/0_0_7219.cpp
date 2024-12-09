#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    bool possible = true;
    vector<pair<int, int>> moves;

    // Read the grid and check for evil cells
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'E') {
                bool canPurify = false;
                for (int k = 0; k < n; k++) {
                    if (grid[i][k] == '.' || grid[k][j] == '.') {
                        canPurify = true;
                        break;
                    }
                }
                if (!canPurify) {
                    possible = false;
                    break;
                }
            }
        }
        if (!possible) {
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
    } else {
        // Find the cells to purify
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 'E') {
                    moves.push_back({i + 1, j + 1});
                }
            }
        }

        // Output the moves
        cout << moves.size() << endl;
        for (auto move : moves) {
            cout << move.first << " " << move.second << endl;
        }
    }

    return 0;
}