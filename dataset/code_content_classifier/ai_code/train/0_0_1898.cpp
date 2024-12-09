#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int W, H, N;
    while (true) {
        cin >> W >> H >> N;
        if (W == 0 && H == 0 && N == 0) {
            break;
        }

        vector<pair<pair<int, int>, pair<int, int>>> walls;
        for (int i = 0; i < N; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            walls.push_back({{x1, y1}, {x2, y2}});
        }

        int xE, yE, xE_, yE_, xX, yX;
        cin >> xE >> yE >> xE_ >> yE_ >> xX >> yX;

        vector<vector<bool>> visited(H, vector<bool>(W, false));
        queue<tuple<int, int, int>> q;
        q.push({xE, yE, 0});
        visited[yE][xE] = true;
        int steps = -1;

        while (!q.empty()) {
            int x, y, cur_steps;
            tie(x, y, cur_steps) = q.front();
            q.pop();

            if (x == xX && y == yX) {
                steps = cur_steps;
                break;
            }

            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (newX >= 0 && newX < W && newY >= 0 && newY < H && !visited[newY][newX]) {
                    bool valid = true;
                    for (auto& wall : walls) {
                        if ((wall.first.first == wall.second.first && x == wall.first.first && ((y >= wall.first.second && y <= wall.second.second) || (y <= wall.first.second && y >= wall.second.second))) || 
                            (wall.first.second == wall.second.second && y == wall.first.second && ((x >= wall.first.first && x <= wall.second.first) || (x <= wall.first.first && x >= wall.second.first)))) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        q.push({newX, newY, cur_steps + 1});
                        visited[newY][newX] = true;
                    }
                }
            }
        }

        if (steps == -1) {
            cout << "Impossible" << endl;
        } else {
            cout << steps << endl;
        }
    }

    return 0;
}