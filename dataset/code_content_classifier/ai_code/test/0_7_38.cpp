#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vector<vector<bool>> exitable(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // Mark exitable cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                if (i == 0 || j == 0 || (exitable[i-1][j] && exitable[i][j-1])) {
                    exitable[i][j] = true;
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int x1, x2;
        cin >> x1 >> x2;

        bool determinable = false;

        // Check if subgrid is determinable
        for (int i = 0; i < n; i++) {
            if (x1 > 1 && exitable[i][x1-2]) {
                determinable = true;
                break;
            }
            if (x2 < m && exitable[i][x2-1]) {
                determinable = true;
                break;
            }
        }

        cout << (determinable ? "YES" : "NO") << endl;
    }

    return 0;
}