#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int dfs(int i, int j, int targetI, int targetJ) {
    if (!isValid(i, j) || grid[i][j] == 0 || visited[i][j]) {
        return 0;
    }
    visited[i][j] = true;
    return 1 + dfs(i + 1, j, targetI, targetJ) + dfs(i - 1, j, targetI, targetJ) + dfs(i, j + 1, targetI, targetJ) + dfs(i, j - 1, targetI, targetJ);
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            grid[i][j] = (row[j] == '1') ? 1 : 0;
        }
    }

    int maxCycle = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                visited.assign(n, vector<bool>(m, false));
                int cycleLength = dfs(i, j, i, j);
                if (cycleLength > 2) {
                    maxCycle = max(maxCycle, cycleLength);
                }
            }
        }
    }

    if (maxCycle == 0) {
        cout << 0 << endl;
    } else {
        cout << maxCycle * 2 << endl;
    }

    return 0;
}