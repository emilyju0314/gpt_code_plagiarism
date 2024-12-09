#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e8;

int H, W;
vector<string> grid;
int dp[60][80][16][2]; // dp[h][w][g][d], g is the number of gold picked up, d is the direction of dash mode

int dirX[] = {0, 0, 1, -1};
int dirY[] = {1, -1, 0, 0};

void bfs() {
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 0;
    queue<pair<int, pair<int, pair<int, int>>>> q;
    q.push({0, {0, {0, 0}}});

    while (!q.empty()) {
        int h = q.front().first;
        int w = q.front().second.first;
        int gold = q.front().second.second.first;
        int dir = q.front().second.second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nh = h + dirX[i];
            int nw = w + dirY[i];

            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if (grid[nh][nw] == '#') continue;

            int nd = dir;

            if (grid[nh][nw] == '^') {
                if (nd == 1 && nh == h + 2 * dirX[i] && nw == w + 2 * dirY[i]) {
                    nh += dirX[i];
                    nw += dirY[i];
                    nd = 0;
                } else if (nd == 1) continue;
            }

            int ng = gold;
            if (grid[nh][nw] == '*') ng++;

            if (dp[nh][nw][ng][nd] == -1 || dp[nh][nw][ng][nd] > dp[h][w][gold][dir] + 1) {
                dp[nh][nw][ng][nd] = dp[h][w][gold][dir] + 1;
                q.push({nh, {nw, {ng, nd}}});
            }
        }
    }
}

int main() {
    while (true) {
        cin >> H >> W;
        if (H == 0 && W == 0) break;

        grid.clear();
        for (int i = 0; i < H; i++) {
            string row;
            cin >> row;
            grid.push_back(row);
        }

        bfs();

        int max_gold = 0, min_cost = INF;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 2; j++) {
                if (dp[H - 1][W - 1][i][j] != -1) {
                    max_gold = max(max_gold, i);
                    min_cost = min(min_cost, dp[H - 1][W - 1][i][j]);
                }
            }
        }

        if (max_gold == 0) {
            cout << "0 0" << endl;
        } else {
            cout << max_gold << " " << min_cost << endl;
        }
    }

    return 0;
}