#include <iostream>
#include <vector>

using namespace std;

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    bool unique = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                bool foundS = false, foundG = false;

                for (pair<int, int> dir : directions) {
                    int x = i + dir.first;
                    int y = j + dir.second;

                    if (isValid(x, y, n)) {
                        if (grid[x][y] == 'S') {
                            foundS = true;
                        } else if (grid[x][y] == 'G') {
                            foundG = true;
                        }
                    }
                }

                if ((foundS && foundG) || (!foundS && !foundG)) {
                    unique = false;
                }
            }
        }
    }

    if (!unique) {
        cout << "NONE" << endl;
    } else {
        cout << "UNIQUE" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.') {
                    cout << "S";
                } else {
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}