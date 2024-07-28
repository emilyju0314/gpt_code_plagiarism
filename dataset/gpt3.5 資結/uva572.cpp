#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void dfs(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '*' || visited[i][j]) {
        return;
    }

    visited[i][j] = true;

    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
    dfs(i - 1, j - 1);
    dfs(i - 1, j + 1);
    dfs(i + 1, j - 1);
    dfs(i + 1, j + 1);
}

int main() {
    while (cin >> m >> n && m != 0 && n != 0) {
        grid.assign(m, vector<char>(n));
        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@' && !visited[i][j]) {
                    dfs(i, j);
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}