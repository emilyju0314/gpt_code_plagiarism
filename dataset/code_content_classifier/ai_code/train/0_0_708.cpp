#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));
    vector<int> row_max(n), col_max(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            row_max[i] = max(row_max[i], A[i][j]);
            col_max[j] = max(col_max[j], A[i][j]);
        }
    }

    vector<int> sorted_row_max = row_max, sorted_col_max = col_max;
    sort(sorted_row_max.begin(), sorted_row_max.end(), greater<int>());
    sort(sorted_col_max.begin(), sorted_col_max.end(), greater<int>());

    vector<vector<int>> A_prime(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A_prime[i][j] = sorted_col_max[j] + sorted_row_max[i] - A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A_prime[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}