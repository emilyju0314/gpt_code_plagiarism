#include <iostream>
#include <vector>

using namespace std;

bool checkRow(vector<vector<int>>& matrix, int row, int m) {
    for (int j = 0; j < m; j++) {
        if (matrix[row][j] == 1) {
            return false;
        }
    }
    return true;
}

bool checkColumn(vector<vector<int>>& matrix, int column, int n) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][column] == 1) {
            return false;
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

        vector<vector<int>> matrix(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        bool ashishWins = true;
        for (int i = 0; i < n; i++) {
            if (checkRow(matrix, i, m)) {
                ashishWins = false;
                break;
            }
        }

        if (ashishWins) {
            for (int j = 0; j < m; j++) {
                if (checkColumn(matrix, j, n)) {
                    ashishWins = false;
                    break;
                }
            }
        }

        if (ashishWins) {
            cout << "Ashish" << endl;
        } else {
            cout << "Vivek" << endl;
        }
    }

    return 0;
}