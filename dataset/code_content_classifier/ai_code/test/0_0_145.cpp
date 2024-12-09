#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Mine {
    int x, y, timer;

    Mine(int x, int y, int timer) : x(x), y(y), timer(timer) {}
};

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<vector<bool>> visited(2001, vector<bool>(2001, false));
        priority_queue<pair<int, pair<int, int>>> pq;

        for (int j = 0; j < n; j++) {
            int x, y, timer;
            cin >> x >> y >> timer;
            visited[x+1000][y+1000] = true;
            pq.push({-timer, {x, y}});
        }

        int ans = 0;

        while (!pq.empty()) {
            int timer = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (visited[x+1000][y+1000]) {
                visited[x+1000][y+1000] = false;

                for (int dx = -k; dx <= k; dx++) {
                    if (dx == 0) continue;
                    int nx = x + dx;
                    if (nx < -1000 || nx > 1000 || visited[nx+1000][y+1000]) continue;
                    pq.push({-timer, {nx, y}});
                }

                for (int dy = -k; dy <= k; dy++) {
                    if (dy == 0) continue;
                    int ny = y+dy;
                    if (ny < -1000 || ny > 1000 || visited[x+1000][ny+1000]) continue;
                    pq.push({-timer, {x, ny}});
                }
            }

            ans = timer;
        }

        cout << ans << endl;
    }

    return 0;
}