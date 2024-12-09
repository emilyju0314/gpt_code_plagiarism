#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int H, W;
vector<string> grid;
vector<vector<int>> dist;
vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool is_valid(int i, int j) {
    return i >= 0 && i < H && j >= 0 && j < W;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (auto dir : directions) {
            int new_i = curr.first + dir.first;
            int new_j = curr.second + dir.second;

            if (is_valid(new_i, new_j) && grid[new_i][new_j] == '.' && dist[new_i][new_j] == -1) {
                dist[new_i][new_j] = dist[curr.first][curr.second] + 1;
                q.push({new_i, new_j});
            }
        }
    }
}

int main() {
    cin >> H >> W;
    grid.resize(H);
    dist.resize(H, vector<int>(W, -1));

    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    bfs();

    if (dist[H-1][W-1] == -1) {
        cout << -1 << endl;
    } else {
        int score = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (grid[i][j] == '.') {
                    score++;
                }
            }
        }
        score -= dist[H-1][W-1] + 1; // Subtract the score of reaching the end
        cout << score << endl;
    }

    return 0;
}