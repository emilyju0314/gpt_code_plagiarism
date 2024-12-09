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
        pair<int, int> lab_pos;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'L') {
                    lab_pos = {i, j};
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    bool reachable = false;
                    for (auto dir : directions) {
                        int new_i = i + dir.first;
                        int new_j = j + dir.second;
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] != '#') {
                            if (new_i == lab_pos.first && new_j == lab_pos.second) {
                                reachable = true;
                                break;
                            }
                        }
                    }
                    if (reachable) {
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