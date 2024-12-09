#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidGrid(vector<string>& grid, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') continue;
            if (i > 0 && grid[i-1][j] == grid[i][j]) return false;
            if (i < n-1 && grid[i+1][j] == grid[i][j]) return false;
            if (j > 0 && grid[i][j-1] == grid[i][j]) return false;
            if (j < m-1 && grid[i][j+1] == grid[i][j]) return false;
        }
    }
    return true;
}

void solveTest() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    bool isValid = isValidGrid(grid, n, m);

    if (!isValid) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                if ((i + j) % 2 == 0) {
                    cout << 'R';
                } else {
                    cout << 'W';
                }
            } else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solveTest();
    }

    return 0;
}