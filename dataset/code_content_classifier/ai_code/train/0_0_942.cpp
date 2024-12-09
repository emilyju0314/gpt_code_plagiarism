#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int h, w;
vector<vector<int>> dist;
vector<pair<int, int>> sources;
vector<pair<int, int>> cities;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(pair<int, int> source) {
    queue<pair<int, int>> q;
    q.push(source);
    dist[source.first][source.second] = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (auto dir : directions) {
            int new_x = current.first + dir.first;
            int new_y = current.second + dir.second;

            if (new_x < 0 || new_x >= h || new_y < 0 || new_y >= w) {
                continue;
            }

            if (dist[new_x][new_y] == INT_MAX) {
                dist[new_x][new_y] = dist[current.first][current.second] + 1;
                q.push({new_x, new_y});
            }
        }
    }
}

int main() {
    while (true) {
        cin >> h >> w;

        if (h == 0 && w == 0) {
            break;
        }

        dist.assign(h, vector<int>(w, INT_MAX));
        sources.clear();
        cities.clear();

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char cell;
                cin >> cell;

                if (cell == 'P') {
                    sources.push_back({i, j});
                } else if (cell == '*') {
                    cities.push_back({i, j});
                }
            }
        }

        int total_cost = 0;

        for (auto source : sources) {
            bfs(source);
            for (auto city : cities) {
                total_cost += dist[city.first][city.second];
            }
        }

        cout << total_cost << endl;
    }

    return 0;
}