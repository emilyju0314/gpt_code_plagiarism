#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    vector<bool> row_evil(n, false);
    vector<bool> col_evil(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'E') {
                row_evil[i] = true;
                col_evil[j] = true;
            }
        }
    }

    vector<pair<int, int>> solutions;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!row_evil[i] && !col_evil[j]) {
                solutions.push_back({i+1, j+1});
                row_evil[i] = col_evil[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!row_evil[i] || !col_evil[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (auto solution : solutions) {
        cout << solution.first << " " << solution.second << endl;
    }

    return 0;
}