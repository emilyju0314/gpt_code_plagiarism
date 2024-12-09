#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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

        int totalOperations = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m/2; j++) {
                totalOperations += abs(matrix[i][j] - matrix[i][m-j-1]);
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n/2; i++) {
                totalOperations += abs(matrix[i][j] - matrix[n-i-1][j]);
            }
        }

        cout << totalOperations << endl;
    }

    return 0;
}