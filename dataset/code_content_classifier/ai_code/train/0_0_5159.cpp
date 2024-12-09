#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char dir[] = {'L', 'R', 'U', 'D'};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> maze(n);
    int start_x, start_y;

    for (int i = 0; i < n; i++) {
        cin >> maze[i];
        if (maze[i].find('X') != string::npos) {
            start_x = i;
            start_y = maze[i].find('X');
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && maze[new_x][new_y] == '.' && !visited[new_x][new_y]) {
                visited[new_x][new_y] = true;
                dist[new_x][new_y] = dist[x][y] + 1;
                parent[new_x][new_y] = {x, y};
                q.push({new_x, new_y});
            }
        }
    }

    pair<int, int> current = {start_x, start_y};
    string answer;

    while (k > 0) {
        int min_dist = k;
        char move = '0';
        
        for (int i = 0; i < 4; i++) {
            int new_x = current.first + dx[i];
            int new_y = current.second + dy[i];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && dist[new_x][new_y] < min_dist) {
                min_dist = dist[new_x][new_y];
                move = dir[i];
            }
        }

        if (move == '0') {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        answer += move;
        current = parent[current.first + dx[move - 'L']][current.second + dy[move - 'L']];
        k--;
    }

    cout << answer << endl;

    return 0;
}