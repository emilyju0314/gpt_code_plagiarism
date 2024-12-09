#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> a;

bool isValidRectangle(int r, int c, int h, int w) {
    int value = a[r][c];
    for (int i = r; i < r + h; i++) {
        for (int j = c; j < c + w; j++) {
            if (a[i][j] != value) {
                return false;
            }
        }
    }
    return true;
}

int countCellsToChange(int r, int c, int h, int w) {
    int count = 0;
    for (int i = r; i < r + h; i++) {
        for (int j = c; j < c + w; j++) {
            if (a[i][j] == 1) {
                count++;
            }
        }
    }
    return min(count, h * w - count);
}

int main() {
    cin >> n >> m >> k;
    a.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int minCellsToChange = INT_MAX;

    for (int h = 1; h <= n; h++) {
        for (int w = 1; w <= m; w++) {
            for (int r = 0; r + h <= n; r++) {
                for (int c = 0; c + w <= m; c++) {
                    if (isValidRectangle(r, c, h, w)) {
                        int cellsToChange = countCellsToChange(r, c, h, w);
                        if (cellsToChange <= k) {
                            minCellsToChange = min(minCellsToChange, cellsToChange);
                        }
                    }
                }
            }
        }
    }

    if (minCellsToChange == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minCellsToChange << endl;
    }

    return 0;
}