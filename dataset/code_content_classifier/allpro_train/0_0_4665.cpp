#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct Node {
    int x, y, dir, cost;
};

int main() {
    int h, w;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        vector<vector<int>> board(h, vector<int>(w));
        vector<vector<int>> cost(h, vector<int>(w, INT_MAX));
        int gx, gy;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
                if (board[i][j] == 4) {
                    gx = j;
                    gy = i;
                }
            }
        }

        int c0, c1, c2, c3;
        cin >> c0 >> c1 >> c2 >> c3;

        // BFS
        queue<Node> q;
        q.push({0, 0, 1, 0});
        cost[0][0] = 0;

        while (!q.empty()) {
            Node current = q.front();
            q.pop();

            if (current.x == gx && current.y == gy) {
                cout << current.cost << endl;
                break;
            }

            int dx[] = {0, 1, 0, -1};
            int dy[] = {-1, 0, 1, 0};

            int cost2dir[] = {c0, c1, c2, c3};

            for (int i = 0; i < 4; i++) {
                int nextCost = current.cost + cost2dir[i];

                if (nextCost < cost[current.y][current.x]) {
                    cost[current.y][current.x] = nextCost;
                }

                Node next = {current.x + dx[current.dir], current.y + dy[current.dir], current.dir, nextCost};

                if (next.x >= 0 && next.x < w && next.y >= 0 && next.y < h) {
                    if (board[next.y][next.x] != 4) {
                        next.dir = (current.dir + i) % 4;
                        q.push(next);
                    }
                }
            }
        }
    }

    return 0;
}