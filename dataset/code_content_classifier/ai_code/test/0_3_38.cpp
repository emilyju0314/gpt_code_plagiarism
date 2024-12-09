#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> up(n, vector<int>(m));
    vector<vector<int>> left(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Calculate up exitable cells
    for (int j = 0; j < m; j++) {
        int up_cell = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == '.') {
                up_cell++;
            } else {
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            up[i][j] = up_cell;
        }
    }

    // Calculate left exitable cells
    for (int i = 0; i < n; i++) {
        int left_cell = 0;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                left_cell++;
            } else {
                break;
            }
        }
        for (int j = 0; j < m; j++) {
            left[i][j] = left_cell;
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int x1, x2;
        cin >> x1 >> x2;

        bool determinable = true;
        for (int i = 0; i < n; i++) {
            if (up[i][x2-1] < n - i && left[i][x2-1] < x2-x1) {
                determinable = false;
                break;
            }
        }

        cout << (determinable ? "YES" : "NO") << endl;
    }

    return 0;
}