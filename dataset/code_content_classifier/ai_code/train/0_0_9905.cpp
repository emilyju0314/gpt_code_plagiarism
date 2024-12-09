#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<char>> field;
vector<vector<bool>> visited;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && field[x][y] == '.';
}

void dfs(int x, int y) {
    visited[x][y] = true;

    if (isValid(x + 1, y) && !visited[x + 1][y]) {
        dfs(x + 1, y);
    }
    if (isValid(x, y + 1) && !visited[x][y + 1]) {
        dfs(x, y + 1);
    }
}

int main() {
    cin >> n >> m;

    field.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1--; y1--; x2--; y2;

        visited = vector<vector<bool>(n, vector<bool>(m, false));

        dfs(x1, y1);

        if (visited[x2][y2]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}