#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    int n;
    cin >> n;

    set<pair<int, int>> furniture;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        furniture.insert({x, y});
    }

    int lx, ly;
    cin >> lx >> ly;

    int dx[] = {0, 1, 1, 0, -1, -1};
    int dy[] = {1, 0, -1, -1, 0, 1};

    const int INF = 1e9;
    int ignore = INF;

    queue<tuple<int, int, int, int>> q;
    q.push({sx, sy, 0, 0});

    set<tuple<int, int, int, int>> visited;
    visited.insert({sx, sy, 0, 0});

    while (!q.empty()) {
        int x, y, t, ignores;
        tie(x, y, t, ignores) = q.front();
        q.pop();

        if (x == gx && y == gy) {
            ignore = min(ignore, ignores);
        }

        int direction = abs(x * y * t) % 6;

        for (int i = direction, cnt = 0; cnt < 6; i = (i + 1) % 6, cnt++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= -lx && nx <= lx && ny >= -ly && ny <= ly && furniture.count({nx, ny}) == 0) {
                int next_ignores = ignores;
                if (i != direction) next_ignores++;

                if (visited.count({nx, ny, (t + 1) % 6, next_ignores}) == 0) {
                    visited.insert({nx, ny, (t + 1) % 6, next_ignores});
                    q.push({nx, ny, (t + 1) % 6, next_ignores});
                }
            }
        }
    }

    if (ignore == INF) {
        cout << -1 << endl;
    } else {
        cout << ignore << endl;
    }

    return 0;
}