#include <iostream>
#include <vector>

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

    long long sum = 0;
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
            if(matrix[i][j] == 0) {
                int min_val = min(matrix[i-1][j], matrix[i+1][j]);
                min_val = min(min_val, matrix[i][j-1]);
                min_val = min(min_val, matrix[i][j+1]);
                matrix[i][j] = min_val + 1;
            }
            sum += matrix[i][j];
            if(matrix[i][j] <= matrix[i-1][j] || matrix[i][j] <= matrix[i+1][j] || matrix[i][j] <= matrix[i][j-1] || matrix[i][j] <= matrix[i][j+1]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << sum << endl;

    return 0;
}