#include <iostream>
#include <vector>

using namespace std;

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
    // Check if there is a unique way to create a mastapeece
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                continue;
            }
            int count = 0;
            if (i - 1 >= 0 && grid[i - 1][j] == grid[i][j]) {
                count++;
            }
            if (i + 1 < n && grid[i + 1][j] == grid[i][j]) {
                count++;
            }
            if (j - 1 >= 0 && grid[i][j - 1] == grid[i][j]) {
                count++;
            }
            if (j + 1 < n && grid[i][j + 1] == grid[i][j]) {
                count++;
            }
            if (count != 2) {
                unique = false;
            }
        }
    }

    if (!unique) {
        cout << "NONE" << endl;
    } else {
        cout << "UNIQUE" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '.') {
                    cout << grid[i][j];
                } else {
                    if ((i + j) % 2 == 0) {
                        cout << 'S';
                    } else {
                        cout << 'G';
                    }
                }
            }
            cout << endl;
        }
    }

    return 0;
}