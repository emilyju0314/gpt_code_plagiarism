#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <cmath>

using namespace std;

const int INF = 1e9;

struct Point {
    int x, y;
};

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

bool is_valid(Point p, vector<Point>& poly) {
    int crossings = 0;
    for (int i = 0; i < poly.size(); i++) {
        int j = (i + 1) % poly.size();
        if ((poly[i].y <= p.y && poly[j].y > p.y) || (poly[i].y > p.y && poly[j].y <= p.y)) {
            double vm = (double)(p.y - poly[i].y) / (poly[j].y - poly[i].y);
            if (p.x < poly[i].x + vm * (poly[j].x - poly[i].x)) crossings++;
        }
    }
    return (crossings % 2 != 0);
}

int bfs(Point start, Point goal, vector<Point>& poly) {
    set<tuple<int, int, int>> visited;
    queue<tuple<int, int, int>> q;

    q.push({start.x, start.y, 0});

    while (!q.empty()) {
        int x, y, dist;
        tie(x, y, dist) = q.front();
        q.pop();

        if (x == goal.x && y == goal.y) {
            return dist;
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_valid({nx, ny}, poly) && visited.find({nx, ny, i}) == visited.end()) {
                visited.insert({nx, ny, i});
                q.push({nx, ny, dist + 1});
            }
        }
    }

    return INF;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;

        vector<Point> poly(N);
        for (int i = 0; i < N; i++) {
            cin >> poly[i].x >> poly[i].y;
        }

        cout << bfs({sx, sy}, {gx, gy}, poly) << endl;
    }

    return 0;
}