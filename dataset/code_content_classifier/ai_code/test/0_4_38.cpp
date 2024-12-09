#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vector<vector<bool>> exitable(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // Calculate whether each cell is exitable
    for (int i = 0; i < n; i++) {
        bool exitable_row = true;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                exitable_row = false;
            }
            exitable[i][j] = exitable_row;
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int x1, x2;
        cin >> x1 >> x2;

        x1--;
        x2--;

        bool determinable = false;

        for (int i = 0; i < n; i++) {
            if (x1 == 0 || exitable[i][x1] || !exitable[i][x1-1]) {
                determinable = true;
            } else {
                determinable = false;
                break;
            }
            if (x2 < m - 1 && grid[i][x2] == 'X' && exitable[i][x2 + 1]) {
                determinable = false;
                break;
            }
        }

        if (determinable) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}