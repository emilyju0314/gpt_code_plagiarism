#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> cols(k);
    for (int i = 0; i < k; i++) {
        cin >> cols[i];
    }

    vector<int> results(k);
    for (int i = 0; i < k; i++) {
        int curr_col = cols[i];
        int row = 0;
        while (row < n) {
            if (grid[row][curr_col - 1] == 1) {
                curr_col++;
            } else if (grid[row][curr_col - 1] == 3) {
                curr_col--;
            }
            grid[row][curr_col - 1] = 2;
            row++;
        }
        results[i] = curr_col;
    }

    for (int i = 0; i < k; i++) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}