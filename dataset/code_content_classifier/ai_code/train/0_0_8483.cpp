#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int h, w, d, n;
vector<string> grid;
vector<int> rk;
vector<vector<vector<int>>> reaction;
vector<vector<vector<bool>>> visited;

bool isValid(int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h && grid[y][x] != '#';
}

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startY][startX][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int step = visited[y][x][0];
        q.pop();

        if (grid[y][x] == 'D' && step > 0) {
            cout << "Yes" << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && !visited[ny][nx][step]) {
                visited[ny][nx][step] = true;
                q.push({nx, ny});
            }
        }

        if (step + 1 <= d) {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    bool canReach = false;
                    for (int k = 0; k < 4; k++) {
                        int ni = j + dx[k];
                        int nj = i + dy[k];
                        if (isValid(ni, nj) && reaction[j][i][step] == reaction[ni][nj][step+1]) {
                            canReach = true;
                            break;
                        }
                    }
                    if (canReach && !visited[i][j][step+1]) {
                        visited[i][j][step+1] = true;
                        q.push({j, i});
                    }
                }
            }
        }
    }

    cout << "No" << endl;
}

int main() {
    cin >> h >> w >> d >> n;

    grid.resize(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    rk.resize(d);
    for (int i = 0; i < d; i++) {
        cin >> rk[i];
    }

    reaction.assign(h, vector<vector<int>>(w, vector<int>(d+1, 0)));
    for (int i = 0; i < n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        reaction[y][x][s] = 1;
    }

    visited.assign(h, vector<vector<bool>>(w, vector<bool>(d+1, false)));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'D') {
                bfs(j, i);
                return 0;
            }
        }
    }

    cout << "Broken" << endl;

    return 0;
}