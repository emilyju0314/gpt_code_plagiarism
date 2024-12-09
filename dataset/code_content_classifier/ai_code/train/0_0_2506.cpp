#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int min_pushes;

void backtracking(vector<vector<int>>& warehouse, pair<int, int> start, pair<int, int> goal, int pushes) {
    if (pushes >= min_pushes) {
        return;
    }

    if (start == goal) {
        min_pushes = min(min_pushes, pushes);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int new_x = start.first;
        int new_y = start.second;

        while (true) {
            new_x += dx[i];
            new_y += dy[i];

            if (new_x < 0 || new_x >= warehouse.size() || new_y < 0 || new_y >= warehouse[0].size() || warehouse[new_x][new_y] == 1) {
                break;
            }

            if (make_pair(new_x, new_y) == goal) {
                backtracking(warehouse, goal, goal, pushes+1);
            } else if (warehouse[new_x][new_y] == 2) {
                bool moved = false;
                while (new_x + dx[i] >= 0 && new_x + dx[i] < warehouse.size() && new_y + dy[i] >= 0 && new_y + dy[i] < warehouse[0].size() && warehouse[new_x + dx[i]][new_y + dy[i]] == 0) {
                    new_x += dx[i];
                    new_y += dy[i];
                    moved = true;
                }
                if (moved) {
                    warehouse[new_x][new_y] = 2;
                    warehouse[start.first][start.second] = 0;
                    backtracking(warehouse, make_pair(new_x, new_y), goal, pushes+1);
                    warehouse[new_x][new_y] = 0;
                    warehouse[start.first][start.second] = 2;
                }
            }
        }
    }
}

int main() {
    int w, h;

    while (cin >> w >> h && w != 0 && h != 0) {
        vector<vector<int>> warehouse(h, vector<int>(w));

        pair<int, int> start;
        pair<int, int> goal;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> warehouse[i][j];
                if (warehouse[i][j] == 2) {
                    start = make_pair(i, j);
                } else if (warehouse[i][j] == 3) {
                    goal = make_pair(i, j);
                }
            }
        }

        min_pushes = INT_MAX;
        backtracking(warehouse, start, goal, 0);

        if (min_pushes == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << min_pushes << endl;
        }
    }

    return 0;
}