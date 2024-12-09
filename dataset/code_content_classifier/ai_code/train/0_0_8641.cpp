#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> pond(H);
    for (int i = 0; i < H; i++) {
        cin >> pond[i];
    }

    int moves = -1;
    int dr[] = {0, 0, -1, 1};
    int dc[] = {-1, 1, 0, 0};

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    int start_row, start_col;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (pond[i][j] == 'S') {
                start_row = i;
                start_col = j;
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        moves++;
        int size = q.size();
        for (int k = 0; k < size; k++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc] && (pond[nr][nc] == '.' || pond[nr][nc] == 'T')) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    if (!visited[start_row][start_col]) {
        cout << -1 << endl;
    } else {
        int leaves = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (pond[i][j] == 'o' && !visited[i][j]) {
                    leaves++;
                }
            }
        }
        cout << leaves << endl;
    }

    return 0;
}