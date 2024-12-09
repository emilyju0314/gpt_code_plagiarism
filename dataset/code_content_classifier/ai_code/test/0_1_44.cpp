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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                continue;
            }
            int count = 0;
            if (i > 0 && grid[i - 1][j] == grid[i][j]) {
                count++;
            }
            if (i < n - 1 && grid[i + 1][j] == grid[i][j]) {
                count++;
            }
            if (j > 0 && grid[i][j - 1] == grid[i][j]) {
                count++;
            }
            if (j < n - 1 && grid[i][j + 1] == grid[i][j]) {
                count++;
            }
            if (count != 2) {
                cout << "NONE" << endl;
                return 0;
            }
        }
    }

    cout << "UNIQUE" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                if ((i + j) % 2 == 0) {
                    cout << "S";
                } else {
                    cout << "G";
                }
            } else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}