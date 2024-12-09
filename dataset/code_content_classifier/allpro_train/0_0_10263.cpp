#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y];
}

bool solve(int x, int y) {
    if (x == n) {
        return true;
    }

    visited[x][y] = true;

    if (isValid(x, y+1) && grid[x][y] == '.' && grid[x][y+1] == '.') {
        grid[x][y] = '<';
        grid[x][y+1] = '>';
        if (solve(y == m-2 ? x+1 : x, (y+2) % m)) {
            return true;
        }
        grid[x][y] = '.';
        grid[x][y+1] = '.';
    }

    if (isValid(x+1, y) && grid[x][y] == '.' && grid[x+1][y] == '.') {
        grid[x][y] = '^';
        grid[x+1][y] = 'v';
        if (solve(y == m-1 ? x+1 : x, (y+1) % m)) {
            return true;
        }
        grid[x][y] = '.';
        grid[x+1][y] = '.';
    }

    visited[x][y] = false;

    return false;
}

int main() {
    cin >> n >> m;

    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    if (solve(0, 0)) {
        for (int i = 0; i < n; i++) {
            cout << grid[i] << endl;
        }
    } else {
        cout << "Not unique" << endl;
    }

    return 0;
}