#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<char>> field;
vector<vector<bool>> visited;

bool canWin(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || !visited[x][y]) {
        return false;
    }
    
    visited[x][y] = false;

    bool canOpponentWin = true;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0) {
                canOpponentWin &= !canWin(x + dx, y + dy);
            }
        }
    }

    visited[x][y] = true;

    return !canOpponentWin;
}

int main() {
    cin >> n >> m;

    field.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, true));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    bool canRomaWin = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 'X') {
                canRomaWin = true;
            } else {
                visited[i][j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] != 'L') {
                canRomaWin |= canWin(i, j);
            }
        }
    }

    if (canRomaWin) {
        cout << "WIN" << endl;
    } else {
        cout << "LOSE" << endl;
    }

    return 0;
}