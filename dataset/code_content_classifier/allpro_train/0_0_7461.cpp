#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct State {
    int pos;
    int time;
    int dir;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> islands(m);
    for (int i = 0; i < m; i++) {
        cin >> islands[i];
    }

    int g, r;
    cin >> g >> r;

    vector<vector<vector<int>>> dist(n + 1, vector<vector<int>>(g + 1, vector<int>(2, -1)));
    queue<State> q;

    q.push({0, 0, 1});
    dist[0][0][1] = 0;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        for (int new_dir : {-1, 1}) {
            int new_pos = curr.pos + new_dir;
            int new_time = curr.time + 1;
            int new_dir_idx = new_dir == -1 ? 0 : 1;

            // Check if Denis can move to the new position
            if (new_pos >= 0 && new_pos <= n && new_time <= g && (dist[new_pos][new_time][new_dir_idx] == -1)) {
                bool is_island = false;
                for (int island : islands) {
                    if (new_pos == island) {
                        is_island = true;
                        break;
                    }
                }

                if (is_island) {
                    q.push({new_pos, 0, -new_dir});
                    dist[new_pos][0][-new_dir_idx] = dist[curr.pos][curr.time][curr.dir == 1 ? 1 : 0] + 1;
                } else {
                    q.push({new_pos, new_time, new_dir});
                    dist[new_pos][new_time][new_dir_idx] = dist[curr.pos][curr.time][curr.dir == 1 ? 1 : 0] + 1;
                }
            }
        }
    }

    int min_time = -1;
    for (int time = 0; time <= g; time++) {
        if (dist[n][time][0] != -1) {
            int remaining_time = g - time;
            int total_time = dist[n][time][0] + remaining_time * (g + r);

            if (min_time == -1 || total_time < min_time) {
                min_time = total_time;
            }
        }
    }

    cout << min_time << endl;

    return 0;
}