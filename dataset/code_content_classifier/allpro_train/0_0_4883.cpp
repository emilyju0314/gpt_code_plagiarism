#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> visited;
vector<string> table;
int n, m, answer = 0;
bool infinite = false;

void dfs(int x, int y, int cnt) {
    visited[x][y] = cnt;
    if (table[x][y] == 'A' && cnt % 4 == 0) {
        infinite = true;
        return;
    }

    int dirX[] = {0, 1, 0, -1};
    int dirY[] = {1, 0, -1, 0};
    char nextChar[] = {'I', 'M', 'A', 'D'};

    for (int i = 0; i < 4; i++) {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && table[nextX][nextY] == nextChar[i]) {
            if (visited[nextX][nextY] == -1) {
                dfs(nextX, nextY, cnt + 1);
                if (infinite) return;
            } else if (visited[nextX][nextY] < cnt) {
                answer = max(answer, cnt - visited[nextX][nextY] + 1);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    table.resize(n);
    visited.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == 'D') {
                dfs(i, j, 0);
                if (infinite) {
                    cout << "Poor Inna!" << endl;
                    return 0;
                }
            }
        }
    }

    if (answer == 0) {
        cout << "Poor Dima!" << endl;
    } else {
        cout << answer << endl;
    }

    return 0;
}