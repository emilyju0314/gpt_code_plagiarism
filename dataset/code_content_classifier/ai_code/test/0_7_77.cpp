#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int n, m;
std::vector<std::vector<int>> tiles;
std::vector<std::vector<bool>> visited;
std::vector<int> room_sizes;

void bfs(int i, int j) {
    int room_size = 0;
    std::queue<std::pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        room_size++;

        // Check neighbors
        if (x > 0 && !visited[x-1][y] && tiles[x][y] & 8) {
            q.push({x-1, y});
            visited[x-1][y] = true;
        }
        if (y < m-1 && !visited[x][y+1] && tiles[x][y] & 4) {
            q.push({x, y+1});
            visited[x][y+1] = true;
        }
        if (x < n-1 && !visited[x+1][y] && tiles[x][y] & 2) {
            q.push({x+1, y});
            visited[x+1][y] = true;
        }
        if (y > 0 && !visited[x][y-1] && tiles[x][y] & 1) {
            q.push({x, y-1});
            visited[x][y-1] = true;
        }
    }

    room_sizes.push_back(room_size);
}

int main() {
    std::cin >> n >> m;

    tiles = std::vector<std::vector<int>>(n, std::vector<int>(m));
    visited = std::vector<std::vector<bool>>(n, std::vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> tiles[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    std::sort(room_sizes.rbegin(), room_sizes.rend());

    for (int size : room_sizes) {
        std::cout << size << " ";
    }
    std::cout << std::endl;

    return 0;
}