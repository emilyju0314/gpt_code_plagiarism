#include <iostream>
#include <queue>

using namespace std;

const int MAX_W = 50;
const int MAX_H = 50;

struct State {
    int dist;
    int tx, ty, kx, ky;
};

int main() {
    int W, H;
    while (cin >> W >> H && W != 0 && H != 0) {
        int tx, ty, kx, ky;
        cin >> tx >> ty >> kx >> ky;

        int grid[MAX_H][MAX_W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> grid[i][j];
            }
        }

        bool visited[MAX_H][MAX_W][MAX_H][MAX_W] = {};
        queue<State> q;
        q.push({0, tx, ty, kx, ky});

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        int ans = -1;
        while (!q.empty()) {
            State s = q.front();
            q.pop();

            if (s.dist > 100) {
                ans = -1;
                break;
            }

            if (s.tx == s.kx && s.ty == s.ky) {
                ans = s.dist;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int ntx = s.tx + dx[i];
                int nty = s.ty + dy[i];
                int nkx = s.kx - dx[i];
                int nky = s.ky - dy[i];

                if (ntx < 0 || ntx >= W || nty < 0 || nty >= H || nkx < 0 || nkx >= W || nky < 0 || nky >= H) {
                    ntx = s.tx;
                    nty = s.ty;
                    nkx = s.kx;
                    nky = s.ky;
                } else if (grid[nty][ntx] == 1) {
                    ntx = s.tx;
                    nty = s.ty;
                } else if (grid[nky][nkx] == 1) {
                    nkx = s.kx;
                    nky = s.ky;
                }

                if (!visited[ntx][nty][nkx][nky]) {
                    visited[ntx][nty][nkx][nky] = true;
                    q.push({s.dist + 1, ntx, nty, nkx, nky});
                }
            }
        }

        if (ans == -1) {
            cout << "NA" << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}