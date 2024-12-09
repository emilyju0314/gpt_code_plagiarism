#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = 0;

    for(int j = 0; j < m; j++) {
        vector<int> columnValues(n);

        for(int i = 0; i < n; i++) {
            columnValues[i] = matrix[i][j];
        }

        int moves = 0;
        for(int i = 0; i < n; i++) {
            if(columnValues[i] != (i * m) + (j + 1)) {
                int target = (i * m) + (j + 1);
                int diff = abs(columnValues[i] - target);
                moves = max(moves, diff);
            }
        }

        result += moves;
    }

    cout << result << endl;

    return 0;
}