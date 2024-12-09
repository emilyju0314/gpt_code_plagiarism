#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<string> table;
vector<int> treasure_values;
int start_x, start_y;
int max_profit = 0;

void dfs(int x, int y, int mask, int visited, int profit) {
    visited |= 1 << (x*m + y); // Mark current cell as visited
    if (x != start_x || y != start_y) {
        profit += treasure_values[table[x][y] - '1'];
    }
    max_profit = max(max_profit, profit);

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && (visited & (1 << (nx*m + ny))) == 0 && table[nx][ny] != '#' && !(nx == start_x && ny == start_y) && table[nx][ny] != 'B') {
            int new_mask = mask;
            if (table[nx][ny] >= '1' && table[nx][ny] <= '8') {
                new_mask |= 1 << (table[nx][ny] - '1');
            }
            dfs(nx, ny, new_mask, visited, profit);
        }
    }
}

int main() {
    cin >> n >> m;
    table.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
        for (int j = 0; j < m; j++) {
            if (table[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
        }
    }

    int num_treasures;
    cin >> num_treasures;
    treasure_values.resize(num_treasures);
    for (int i = 0; i < num_treasures; i++) {
        cin >> treasure_values[i];
    }

    dfs(start_x, start_y, 0, 0, 0);

    cout << max_profit << endl;

    return 0;
}