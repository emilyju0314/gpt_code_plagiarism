#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Position {
    int x, y;
};

struct State {
    vector<Position> dicePositions;
    int moves;
};

bool isValid(int x, int y, int r, int c) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

int bfs(vector<vector<char>>& grid, int r, int c) {
    Position storage[6];
    vector<Position> dicePositions;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (isdigit(grid[i][j])) {
                storage[grid[i][j] - '0'].x = i;
                storage[grid[i][j] - '0'].y = j;
            } else if (grid[i][j] == 'o') {
                dicePositions.push_back({i, j});
            }
        }
    }

    queue<State> q;
    q.push({dicePositions, 0});

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (all_of(current.dicePositions.begin(), current.dicePositions.end(), [&](Position p) {
            return p.x == storage[grid[p.x][p.y] - '0'].x && p.y == storage[grid[p.x][p.y] - '0'].y;
        })) {
            return current.moves;
        }

        // TODO: Implement dice movement and BFS logic

    }

    return -1;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    int result = bfs(grid, r, c);

    cout << result << endl;

    return 0;
}