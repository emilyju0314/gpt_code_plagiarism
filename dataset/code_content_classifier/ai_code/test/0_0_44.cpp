#include <iostream>
#include <vector>
using namespace std;

bool checkValid(int n, vector<vector<char>>& grid, int row, int col, char color) {
    if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != color) {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    bool unique = true;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<char>> solution = grid;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                for (char c : {'S', 'G'}) {
                    bool isPossible = true;
                    for (int k = 0; k < 4; k++) {
                        int newRow = i + dirs[k][0];
                        int newCol = j + dirs[k][1];
                        if (checkValid(n, grid, newRow, newCol, c)) {
                            isPossible = false;
                            break;
                        }
                    }
                    if (isPossible) {
                        solution[i][j] = c;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != solution[i][j]) {
                unique = false;
                break;
            }
        }
        if (!unique) {
            break;
        }
    }

    if (unique) {
        cout << "UNIQUE" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solution[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "NONE" << endl;
    }

    return 0;
}