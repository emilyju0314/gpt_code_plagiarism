#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
    int row, col, left, right;
};

int main() {
    int n, m, r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;

    vector<vector<char>> labyrinth(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
        }
    }

    queue<Cell> q;
    q.push({r-1, c-1, x, y});
    visited[r-1][c-1] = true;

    int count = 1;  // Starting cell is always reachable
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while(!q.empty()) {
        Cell cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newRow = cur.row + dx[i];
            int newCol = cur.col + dy[i];

            if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || visited[newRow][newCol] || labyrinth[newRow][newCol] == '*') {
                continue;
            }

            if(dy[i] < 0) {
                if(cur.left == 0) {
                    continue;
                }
                q.push({newRow, newCol, cur.left - 1, cur.right});
            } else if(dy[i] > 0) {
                if(cur.right == 0) {
                    continue;
                }
                q.push({newRow, newCol, cur.left, cur.right - 1});
            } else {
                q.push({newRow, newCol, cur.left, cur.right});
            }

            visited[newRow][newCol] = true;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}