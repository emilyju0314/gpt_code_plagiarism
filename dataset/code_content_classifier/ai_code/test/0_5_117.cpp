#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> grid(n, vector<char>(m));
        pair<int, int> labPos;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'L') {
                    labPos = {i, j};
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    bool canReachLab = false;
                    for (auto& dir : directions) {
                        int newRow = i + dir.first;
                        int newCol = j + dir.second;
                        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                            if (grid[newRow][newCol] == 'L' || (newRow == labPos.first && newCol == labPos.second)) {
                                canReachLab = true;
                                break;
                            }
                        }
                    }
                    if (canReachLab) {
                        grid[i][j] = '+';
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}