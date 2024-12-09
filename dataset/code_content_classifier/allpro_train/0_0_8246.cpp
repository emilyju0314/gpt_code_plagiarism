#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));
    vector<int> maxRows(n, 0), maxCols(m, 0);

    // Read matrix A and store maximum values in rows and columns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            maxRows[i] = max(maxRows[i], A[i][j]);
            maxCols[j] = max(maxCols[j], A[i][j]);
        }
    }

    // Sort row and column maximum values in descending order
    sort(maxRows.begin(), maxRows.end(), greater<int>());
    sort(maxCols.begin(), maxCols.end(), greater<int>());

    // Create and fill the new matrix A'
    vector<vector<int>> result(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j < m / 2) {
                result[i][j] = maxRows[i];
            } else {
                result[i][j] = maxCols[j];
            }
        }
    }

    // Output the matrix A'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}