#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int row;
            cin >> row;
            vector<int> temp = matrix[row-1];
            for (int j = 0; j < m; j++) {
                matrix[row-1][(j + 1) % m] = temp[j];
            }
        } else if (type == 2) {
            int col;
            cin >> col;
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                temp.push_back(matrix[j][col-1]);
            }
            for (int j = 0; j < n; j++) {
                matrix[(j + 1) % n][col-1] = temp[j];
            }
        } else {
            int row, col, val;
            cin >> row >> col >> val;
            matrix[row-1][col-1] = val;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}