#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    vector<int> erased_columns;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1) {
                erased_columns.push_back(j);
            }
        }
    }

    sort(erased_columns.begin(), erased_columns.end());

    for (int i = 0; i < m; i++) {
        if (find(erased_columns.begin(), erased_columns.end(), i) == erased_columns.end()) {
            cout << i + 1 << " ";
        }
    }

    for (int i = 0; i < erased_columns.size(); i++) {
        cout << erased_columns[i] + 1 << " ";
    }

    return 0;
}