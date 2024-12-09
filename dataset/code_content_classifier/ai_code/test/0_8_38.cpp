#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<bool> exitableRow(n, false);
    vector<bool> exitableCol(m, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') {
                exitableRow[i] = true;
                exitableCol[j] = true;
            }
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        x1--; x2--;

        bool determinable = false;
        for (int j = 0; j < n; j++) {
            if (exitableRow[j] && j >= x1 && j <= x2 && exitableCol[x1]) {
                determinable = true;
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