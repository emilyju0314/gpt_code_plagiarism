#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // Read the row data
        vector<vector<int>> rows(n, vector<int>(m));
        unordered_map<int, pair<int, int>> rowMapping;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> rows[i][j];
                rowMapping[rows[i][j]] = make_pair(i, j);
            }
        }

        // Read the column data
        vector<vector<int>> columns(m, vector<int>(n));
        unordered_map<int, pair<int, int>> colMapping;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> columns[i][j];
                colMapping[columns[i][j]] = make_pair(j, i);
            }
        }

        // Construct the final matrix
        vector<vector<int>> result(n, vector<int>(m));
        for (int i = 1; i <= n*m; i++) {
            result[rowMapping[i].first][rowMapping[i].second] = i;
        }

        // Output the final matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}