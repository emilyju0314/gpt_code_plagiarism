#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<int> rowSums(n, 0);
    vector<int> colSums(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            rowSums[i] += grid[i][j];
            colSums[j] += grid[i][j];
        }
    }

    vector<pair<string, int>> moves;
    int totalMoves = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != rowSums[i] + colSums[j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        while (rowSums[i] > 0) {
            moves.push_back(make_pair("row", i + 1));
            totalMoves++;
            rowSums[i]--;
        }
    }

    for (int j = 0; j < m; j++) {
        while (colSums[j] > 0) {
            moves.push_back(make_pair("col", j + 1));
            totalMoves++;
            colSums[j]--;
        }
    }

    cout << totalMoves << endl;
    for (auto move : moves) {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}