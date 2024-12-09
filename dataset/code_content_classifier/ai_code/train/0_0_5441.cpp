#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a block
struct Block {
    int color;
    int orientation;
    int x, y;
};

int main() {
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        int xs, ys, xg, yg;
        cin >> xs >> ys >> xg >> yg;

        int n;
        cin >> n;

        vector<vector<int>> board(h, vector<int>(w, 0)); // Initialize board to all 0's

        vector<Block> blocks(n);
        
        for (int i = 0; i < n; i++) {
            int color, orientation, x, y;
            cin >> color >> orientation >> x >> y;
            blocks[i] = {color, orientation, x, y};

            if (orientation == 0) {
                board[y][x] = color;
                board[y][x + 1] = color;
            } else {
                board[y][x] = color;
                board[y + 1][x] = color;
            }
        }

        vector<vector<bool>> visited(h, vector<bool>(w, false));

        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};

        bool found = false;

        auto dfs = [&](int x, int y) {
            if (x < 0 || x >= w || y < 0 || y >= h || visited[y][x]) return;
            visited[y][x] = true;

            if (x == xg - 1 && y == yg - 1) {
                found = true;
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                    if (board[ny][nx] == board[y][x]) {
                        dfs(nx, ny);
                    }
                }
            }
        };

        dfs(xs - 1, ys - 1);

        if (found) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }
    }

    return 0;
}