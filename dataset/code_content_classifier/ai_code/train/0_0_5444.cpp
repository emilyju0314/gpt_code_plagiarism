#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct Point {
    int x, y, steps;
};

int main() {
    int w, h;
    while (cin >> w >> h && w != 0 && h != 0) {
        vector<string> room(h);
        for (int i = 0; i < h; i++) {
            cin >> room[i];
        }

        pair<int, int> start;
        vector<pair<int, int>> dirty_tiles;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (room[i][j] == 'o') {
                    start = {i, j};
                } else if (room[i][j] == '*') {
                    dirty_tiles.push_back({i, j});
                }
            }
        }

        int num_dirty_tiles = dirty_tiles.size();
        vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(w, vector<bool>(num_dirty_tiles, false)));

        queue<Point> q;
        q.push({start.first, start.second, 0});
        visited[start.first][start.second][0] = true;

        int min_moves = -1;
        while (!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            int steps = q.front().steps;
            q.pop();

            if (num_dirty_tiles == 0) {
                min_moves = steps;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if (new_x >= 0 && new_x < h && new_y >= 0 && new_y < w && room[new_x][new_y] != 'x') {
                    if (room[new_x][new_y] == '*') {
                        int tile_idx = -1;
                        for (int j = 0; j < dirty_tiles.size(); j++) {
                            if (dirty_tiles[j].first == new_x && dirty_tiles[j].second == new_y) {
                                tile_idx = j;
                                break;
                            }
                        }

                        if (tile_idx != -1 && !visited[new_x][new_y][tile_idx]) {
                            visited[new_x][new_y][tile_idx] = true;
                            q.push({new_x, new_y, steps + 1});

                            vector<vector<vector<bool>>> updated_visited = visited;
                            updated_visited[new_x][new_y][tile_idx] = true;
                            q.push({new_x, new_y, steps + 1});
                        }
                    } else if (!visited[new_x][new_y][0]) {
                        visited[new_x][new_y][0] = true;
                        q.push({new_x, new_y, steps + 1});
                    }
                }
            }
        }

        cout << min_moves << endl;
    }

    return 0;
}