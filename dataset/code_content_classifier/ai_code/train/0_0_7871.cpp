#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<string> area(H);
    pair<int, int> start;
    vector<pair<int, int>> foods(N);

    for (int i = 0; i <= H; i++) {
        getline(cin, area[i]);
        for (int j = 0; j < W; j++) {
            if (area[i][j] == 'S') {
                start = {i, j};
            } else if (area[i][j] >= '1' && area[i][j] <= '9') {
                foods[area[i][j] - '1'] = {i, j};
            }
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    queue<tuple<int, int, int, int, int>> q; // x, y, steps, current food, visited
    q.push({start.first, start.second, 0, 0, 0});

    int ans = -1;
    unordered_map<string, int> seen;

    while (!q.empty()) {
        int x, y, steps, food, visited;
        tie(x, y, steps, food, visited) = q.front();
        q.pop();

        if (food == N) {
            ans = steps;
            break;
        }

        string key = to_string(x) + "," + to_string(y) + "," + to_string(food) + "," + to_string(visited);
        if (seen.find(key) != seen.end()) {
            continue;
        }
        seen[key] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && area[nx][ny] != '#') {
                int next_food = food;
                if (area[nx][ny] == 'a' + next_food) {
                    next_food++;
                }
                q.push({nx, ny, steps + 1, next_food, visited | (1 << (nx * W + ny))});
            }
        }
    }

    cout << ans << endl;

    return 0;
}