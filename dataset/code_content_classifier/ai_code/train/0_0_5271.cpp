#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        vector<vector<int>> cliff(h, vector<int>(w));
        Point start;
        vector<Point> end;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                char c;
                cin >> c;
                if (c == 'S') {
                    start.x = x;
                    start.y = y;
                    cliff[y][x] = 0;
                } else if (c == 'T') {
                    end.push_back({x, y});
                    cliff[y][x] = 0;
                } else if (c == 'X') {
                    cliff[y][x] = -1;
                } else {
                    cliff[y][x] = c - '0';
                }
            }
        }

        queue<Point> q;
        q.push(start);

        vector<vector<int>> time(h, vector<int>(w, INT_MAX));
        time[start.y][start.x] = 0;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            Point current = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nextX = current.x + dx[i];
                int nextY = current.y + dy[i];

                if (nextX >= 0 && nextX < w && nextY >= 0 && nextY < h && cliff[nextY][nextX] != -1) {
                    int movingTime = (current.x != nextX) ? 1 : 0;
                    int slipTime = cliff[nextY][nextX];

                    if (time[current.y][current.x] + slipTime + movingTime < time[nextY][nextX]) {
                        time[nextY][nextX] = time[current.y][current.x] + slipTime + movingTime;
                        q.push({nextX, nextY});
                    }
                }
            }
        }

        int minTime = INT_MAX;
        for (Point p : end) {
            minTime = min(minTime, time[p.y][p.x]);
        }

        if (minTime == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << minTime << endl;
        }
    }

    return 0;
}