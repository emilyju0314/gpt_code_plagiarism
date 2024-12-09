#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> silence(n, vector<int>(m));
    vector<pair<int, pair<int, int>>> cells;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> silence[i][j];
            cells.push_back({silence[i][j], {i, j}});
        }
    }

    sort(cells.begin(), cells.end());

    vector<vector<int>> minRow(n, vector<int>(m, -1));
    vector<vector<int>> maxRow(n, vector<int>(m, -1));
    vector<vector<int>> minCol(n, vector<int>(m, -1));
    vector<vector<int>> maxCol(n, vector<int>(m, -1));

    for (int i = 0; i < n * m; i++) {
        int x = cells[i].second.first;
        int y = cells[i].second.second;

        minRow[x][y] = x;
        maxRow[x][y] = x;
        minCol[x][y] = y;
        maxCol[x][y] = y;

        if (x > 0 && minRow[x-1][y] != -1) {
            minRow[x][y] = min(minRow[x][y], minRow[x-1][y]);
            maxRow[x][y] = max(maxRow[x][y], maxRow[x-1][y]);
        }

        if (y > 0 && minCol[x][y-1] != -1) {
            minCol[x][y] = min(minCol[x][y], minCol[x][y-1]);
            maxCol[x][y] = max(maxCol[x][y], maxCol[x][y-1]);
        }
    }

    long long count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count += (long long)(maxRow[i][j] - minRow[i][j] + 1) * (maxCol[i][j] - minCol[i][j] + 1);
        }
    }

    cout << count << endl;

    return 0;
}