#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++) {
            grid[i][j] = row[j] - '0';
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 2; k++) {
                if(dp[i][j][k] == -1) {
                    int c = grid[i][j];
                    dp[i][j][c] = 0;

                    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    vector<pair<int, int>> q = {{i, j}};

                    while(!q.empty()) {
                        pair<int, int> cur = q.back();
                        q.pop_back();

                        int x = cur.first, y = cur.second;
                        visited[x][y] = true;

                        for(auto dir : dirs) {
                            int nx = x + dir.first, ny = y + dir.second;
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                                if(grid[nx][ny] == c) {
                                    dp[i][j][k] = 1;
                                } else {
                                    q.push_back({nx, ny});
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < t; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        x--; y--;

        int color = grid[x][y];
        int ans = dp[x][y][p % 2];
        cout << ans << endl;
    }

    return 0;
}