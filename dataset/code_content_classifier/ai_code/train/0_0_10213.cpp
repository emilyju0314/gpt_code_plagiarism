#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>

using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    int sx, sy;
    cin >> sx >> sy;
    sx--;
    sy--;

    vector<vector<int>> grid(H, vector<int>(W, 0));

    vector<vector<int>> grid_dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        vector<pair<int, int>> path;
        for (int j = 0; j < L; j++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            grid[y][x]++;
            path.push_back({x, y});
        }

        grid[path[L-1].second][path[L-1].first] = -(i + 1);
    }

    queue<tuple<int, int, unordered_set<int>, int>> q;
    q.push({sx, sy, {}, 0});

    while (!q.empty()) {
        int x, y, visited, time;
        tie(x, y, visited, time) = q.front();
        q.pop();

        if (grid[y][x] < 0) {
            if (visited.size() == N) {
                cout << time << endl;
                return 0;
            }
            continue;
        }

        for (auto dir : grid_dirs) {
            int new_x = x + dir[0];
            int new_y = y + dir[1];

            if (new_x >= 0 && new_x < W && new_y >= 0 && new_y < H && grid[new_y][new_x] != -1 && visited.find(grid[new_y][new_x]) == visited.end()) {
                unordered_set<int> new_visited = visited;
                if (grid[new_y][new_x] > 0) {
                    new_visited.insert(grid[new_y][new_x]);
                }
                q.push({new_x, new_y, new_visited, time+1});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}