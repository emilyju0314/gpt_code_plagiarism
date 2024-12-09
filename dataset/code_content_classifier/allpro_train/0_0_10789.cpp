#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> puzzle(n);
    for (int i = 0; i < n; i++) {
        cin >> puzzle[i];
    }

    int minRow = n, maxRow = 0, minCol = m, maxCol = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (puzzle[i][j] == 'X') {
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    for (int i = minRow; i <= maxRow; i++) {
        for (int j = minCol; j <= maxCol; j++) {
            if (puzzle[i][j] != 'X') {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
    return 0;
}