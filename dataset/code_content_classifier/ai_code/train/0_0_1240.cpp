#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            matrix[i][j] = row[j] - '0';
        }
    }

    int changes = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if ((matrix[i][j] + matrix[i+1][j] + matrix[i][j+1] + matrix[i+1][j+1]) % 2 == 0) {
                changes++;
                matrix[i][j] = 1 - matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (matrix[i][m-1] == 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int j = 0; j < m; j++) {
        if (matrix[n-1][j] == 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << changes << endl;

    return 0;
}