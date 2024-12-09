#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool check(int x, int y, int k, vector<vector<int>>& grid) {
    if (x + 1 < n && y - 1 >= 0 && y + 1 < m && grid[x + 1][y - 1] == k && grid[x + 1][y] == k && grid[x + 1][y + 1] == k) {
        return true;
    }
    return false;
}

void placeTurboplows(int cnt, vector<vector<int>>& grid, vector<vector<char>>& res, int x, int y) {
    char c = 'A' + cnt;
    res[x][y] = c;
    grid[x][y] = cnt;
    grid[x + 1][y - 1] = cnt;
    grid[x + 1][y] = cnt;
    grid[x + 1][y + 1] = cnt;
}

int main() {
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<char>> res(n, vector<char>(m, '.'));

    int maxTurboplows = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && j - 1 >= 0 && j + 1 < m && grid[i][j] == 0 && grid[i + 1][j - 1] == 0 && grid[i + 1][j] == 0 && grid[i + 1][j + 1] == 0) {
                maxTurboplows++;
                placeTurboplows(maxTurboplows, grid, res, i, j);
            }
        }
    }

    cout << maxTurboplows << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j];
        }
        cout << endl;
    }

    return 0;
}