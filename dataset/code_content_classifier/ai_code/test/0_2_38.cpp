#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<bool> exitableColumns(m, false);
    vector<int> topmostEmptyRow(m, n);
    vector<int> leftmostEmptyCol(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'X') {
                exitableColumns[j] = false;
            } else {
                exitableColumns[j] = true;
                topmostEmptyRow[j] = min(topmostEmptyRow[j], i);
                leftmostEmptyCol[i] = min(leftmostEmptyCol[i], j);
            }
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x1, x2;
        cin >> x1 >> x2;

        x1--;
        x2--;

        int top = *min_element(topmostEmptyRow.begin() + x1, topmostEmptyRow.begin() + x2 + 1);
        int bottom = x1 == 0 ? 0 : *max_element(leftmostEmptyCol.begin(), leftmostEmptyCol.begin() + x1);
        
        if (top <= bottom) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}