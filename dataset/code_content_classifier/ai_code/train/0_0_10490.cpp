#include <iostream>
#include <vector>
#include <algorithm>

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

        int ans = 0;
        // Iterate over all possible combinations of shifting columns
        for (int mask = 0; mask < (1 << m); mask++) {
            vector<int> max_row_values(n, 0);
            // Apply cyclic shifts based on mask
            for (int j = 0; j < m; j++) {
                if (mask & (1 << j)) {
                    // Shift the j-th column cyclically
                    vector<int> temp_col(matrix.size());
                    for (int i = 0; i < n; i++) {
                        temp_col[(i + 1) % n] = matrix[i][j];
                    }
                    for (int i = 0; i < n; i++) {
                        matrix[i][j] = temp_col[i];
                    }
                }
            }
            // Find max values in each row
            for (int i = 0; i < n; i++) {
                max_row_values[i] = *max_element(matrix[i].begin(), matrix[i].end());
            }
            // Calculate total sum of max row values
            int sum = 0;
            for (int val : max_row_values) {
                sum += val;
            }
            ans = max(ans, sum);
            // Reset matrix to original state
            for (int j = 0; j < m; j++) {
                if (mask & (1 << j)) {
                    vector<int> temp_col(matrix.size());
                    for (int i = 0; i < n; i++) {
                        temp_col[i] = matrix[(i + 1) % n][j];
                    }
                    for (int i = 0; i < n; i++) {
                        matrix[i][j] = temp_col[i];
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}