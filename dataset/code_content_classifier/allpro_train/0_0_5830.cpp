#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> walls;
    for (int i = 0; i < m; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        walls.push_back({l, t});
        walls.push_back({r, -t});
    }

    sort(walls.begin(), walls.end());

    vector<int> walk_times;
    for (int i = 0; i < n; i++) {
        int time;
        cin >> time;
        walk_times.push_back(time);
    }

    for (int i = 0; i < n; i++) {
        int time = walk_times[i];
        int ans = -1;
        int cnt = 0;
        int prev_wall_position = 0;

        for (auto &wall : walls) {
            int position = wall.first;
            int wall_time = wall.second;

            if (cnt == 2 && prev_wall_position < time) {
                ans = position - prev_wall_position;
                break;
            }

            if (cnt == 1) {
                ans = position - time;
                break;
            }

            if (position >= time) {
                prev_wall_position = position;
            }

            cnt += wall_time;
        }

        if (ans == -1) {
            ans = 1e9;
        }

        cout << ans << endl;
    }

    return 0;
}