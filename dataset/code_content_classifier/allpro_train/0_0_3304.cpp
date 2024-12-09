#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

const int N = 1005;
const int K = 45;
int grid[N][N];
int min_time[N][N][K];
int n, m, k;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int color) {
    queue<pair<int, int>> q;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(grid[i][j] == color) {
                q.push({i, j});
                min_time[i][j][color] = 0;
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(auto dir : directions) {
            int new_x = x + dir.first;
            int new_y = y + dir.second;
            if(new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m) {
                if(min_time[new_x][new_y][color] == INT_MAX) {
                    min_time[new_x][new_y][color] = min_time[x][y][color] + 1;
                    q.push({new_x, new_y});
                }
            }  
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            for(int l=1; l<=k; l++) {
                min_time[i][j][l] = INT_MAX;
            }
        }
    }

    for(int color=1; color<=k; color++) {
        bfs(color);
    }

    int q;
    cin >> q;

    for(int i=0; i<q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int min_dist = INT_MAX;
        for(int color=1; color<=k; color++) {
            min_dist = min(min_dist, min_time[r1][c1][color] + min_time[r2][c2][color]);
        }
        cout << (r1 == r2 && c1 == c2 ? 0 : min_dist) << endl;
    }

    return 0;
}