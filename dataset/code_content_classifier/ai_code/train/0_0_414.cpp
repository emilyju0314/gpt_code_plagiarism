#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

const int INF = 1e9;

struct State {
    int x, y, bit;
    State(int x, int y, int bit) : x(x), y(y), bit(bit) {}
};

int main() {
    int W, H;
    std::cin >> W >> H;

    std::vector<std::vector<char>> maze(H, std::vector<char>(W));
    int sx, sy, gx, gy;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cin >> maze[y][x];
            if (maze[y][x] == 'S') {
                sx = x;
                sy = y;
            } else if (maze[y][x] == 'T') {
                gx = x;
                gy = y;
            }
        }
    }

    std::vector<std::vector<int>> scores(10, std::vector<int>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cin >> scores[i][j];
        }
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    std::vector<std::vector<std::vector<int>>> dist(10, std::vector<std::vector<int>>(H, std::vector<int>(W, INF)));
    dist[0][sy][sx] = 0;

    std::priority_queue<std::pair<int, State>, std::vector<std::pair<int, State>>, std::greater<>> pq;
    pq.push({0, State(sx, sy, 0)});

    while (!pq.empty()) {
        auto [d, state] = pq.top();
        pq.pop();

        int x = state.x;
        int y = state.y;
        int bit = state.bit;

        if (x == gx && y == gy) {
            int min_moves = dist[bit][y][x];
            int max_score = 0;
            for (int i = 1; i < 10; i++) {
                for (int j = i+1; j < 10; j++) {
                    if (dist[bit][y][x] < INF && maze[gy][gx] != 'T') {
                        max_score = std::max(max_score, scores[i][j]);
                    }
                }
            }
            std::cout << min_moves << " " << max_score << std::endl;
            return 0;
        }

        if (dist[bit][y][x] < d) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < W && ny >= 0 && ny < H && maze[ny][nx] != '#') {
                int nbit = bit;
                if (maze[ny][nx] >= 'A' && maze[ny][nx] <= 'J') {
                    int item = maze[ny][nx] - 'A';
                    if ((bit >> item) & 1) {
                        continue;
                    }
                    nbit |= (1 << item);
                } else if (maze[ny][nx] >= 'a' && maze[ny][nx] <= 'j') {
                    int item = maze[ny][nx] - 'a';
                    if (!((bit >> item) & 1)) {
                        continue;
                    }
                }
                if (dist[nbit][ny][nx] > dist[bit][y][x] + 1) {
                    dist[nbit][ny][nx] = dist[bit][y][x] + 1;
                    pq.push({dist[nbit][ny][nx], State(nx, ny, nbit)});
                }
            }
        }
    }

    std::cout << "-1" << std::endl;

    return 0;
}