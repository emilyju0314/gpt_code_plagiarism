#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Mine {
    int x, y, timer;
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<vector<bool>> detonated(2*k + 1, vector<bool>(2*k + 1, false));
        vector<vector<bool>> visited(2*k + 1, vector<bool>(2*k + 1, false));

        priority_queue<pair<int, pair<int, int>>> pq; // (time, (x, y))

        for (int i = 0; i < n; i++) {
            int x, y, timer;
            cin >> x >> y >> timer;
            x += k;
            y += k;
            detonated[x][y] = true;
            pq.push({-timer, {x, y}});
        }

        int res = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int time = -top.first;
            int x = top.second.first;
            int y = top.second.second;

            if (detonated[x][y] && !visited[x][y]) {
                visited[x][y] = true;
                res = max(res, time);
            
                for (int dx = -k; dx <= k; dx++) {
                    if (x + dx >= 0 && x + dx <= 2*k && !visited[x + dx][y] && detonated[x + dx][y]) {
                        pq.push({-time, {x + dx, y}});
                    }
                }

                for (int dy = -k; dy <= k; dy++) {
                    if (y + dy >= 0 && y + dy <= 2*k && !visited[x][y + dy] && detonated[x][y + dy]) {
                        pq.push({-time, {x, y + dy}});
                    }
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}