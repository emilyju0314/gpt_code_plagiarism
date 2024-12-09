#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;
    bool possible = true;

    for (int i = 0; i < n; i++) {
        bool hasBlack = false;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                hasBlack = true;
                break;
            }
        }
        if (!hasBlack) {
            count++;
            for (int j = 0; j < m; j++) {
                grid[i][j] = 'x';
            }
        }
    }

    for (int j = 0; j < m; j++) {
        bool hasBlack = false;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == '#') {
                hasBlack = true;
                break;
            }
        }
        if (!hasBlack) {
            count++;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] != 'x') {
                    grid[i][j] = 'x';
                } else {
                    possible = false;
                }
            }
        }
    }

    if (possible) {
        cout << count << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}