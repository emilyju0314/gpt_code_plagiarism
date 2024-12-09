#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<long long> rows_sum(n), cols_sum(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rows_sum[i] += matrix[i][j];
            cols_sum[j] += matrix[i][j];
        }
    }

    sort(rows_sum.begin(), rows_sum.end());
    sort(cols_sum.begin(), cols_sum.end());

    long long max_pleasure = 0;

    for (int i = 0; i <= k; i++) {
        long long cur_pleasure = (long long)((n * rows_sum[n - 1]) + (m * cols_sum[m - 1]));
        max_pleasure = max(max_pleasure, cur_pleasure);

        if (!rows_sum.empty() && !cols_sum.empty()) {
            if (rows_sum[n - 1] >= cols_sum[m - 1]) {
                rows_sum[n - 1] -= p * m;
                cols_sum[m - 1] -= p;
            } else {
                cols_sum[m - 1] -= p * n;
                rows_sum[n - 1] -= p;
            }

            sort(rows_sum.begin(), rows_sum.end());
            sort(cols_sum.begin(), cols_sum.end());
        }
    }

    cout << max_pleasure << endl;

    return 0;
}