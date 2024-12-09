#include <iostream>
#include <vector>

using namespace std;

bool isGoodGrid(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0) {
                int cnt = 0;
                if (i > 0 && grid[i-1][j] > 0) cnt++;
                if (i < n-1 && grid[i+1][j] > 0) cnt++;
                if (j > 0 && grid[i][j-1] > 0) cnt++;
                if (j < m-1 && grid[i][j+1] > 0) cnt++;
                if (cnt != grid[i][j]) return false;
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        // Try increasing every non-zero number by 1 to make it a good grid
        bool possible = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    grid[i][j]++;
                    if (!isGoodGrid(grid)) {
                        grid[i][j]--;
                    }
                }
            }
        }

        if (isGoodGrid(grid)) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << grid[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}