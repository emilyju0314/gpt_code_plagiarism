#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    // Find the dimensions of the matrix
    int n = 1, m = 1;
    while (n * m <= k) {
        if (n <= m) {
            n++;
        } else {
            m++;
        }
    }

    cout << n << " " << m << endl;

    vector<vector<int>> matrix(n, vector<int>(m, 1));

    // Fill the matrix with values to achieve the maximum score of k
    int remaining = k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int value = 1;
            if (j < m - 1 && i + 1 < n) {
                value = (1 << 17) - 1;
            } else if (remaining > 0) {
                value = remaining;
                remaining = 0;
            }
            matrix[i][j] = value;
        }
    }

    // Output the generated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}