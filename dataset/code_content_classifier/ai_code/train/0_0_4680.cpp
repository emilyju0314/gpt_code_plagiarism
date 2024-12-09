#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char grid[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    bool possible = true;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (grid[i][j] == '#' && grid[i-1][j] == '#' && grid[i+1][j] == '#' && grid[i][j-1] == '#' && grid[i][j+1] == '#') {
                grid[i][j] = grid[i-1][j] = grid[i+1][j] = grid[i][j-1] = grid[i][j+1] = '.';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}