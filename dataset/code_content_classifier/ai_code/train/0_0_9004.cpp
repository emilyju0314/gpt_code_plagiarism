#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Position {
    int row, col;
    int bombsUsed;
};

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> cave(H);
    for (int i = 0; i < H; i++) {
        cin >> cave[i];
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));

    queue<Position> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        Position curr = q.front();
        q.pop();

        if (curr.row < 0 || curr.row >= H || curr.col < 0 || curr.col >= W || visited[curr.row][curr.col]) {
            continue;
        }

        visited[curr.row][curr.col] = true;

        if (cave[curr.row][curr.col] == '#') {
            q.push({curr.row, curr.col, curr.bombsUsed + 1});
        } else if (cave[curr.row][curr.col] == 'B') {
            cave[curr.row][curr.col] = '_';
        } else if (curr.row == H - 1 && curr.col == W - 1) {
            cout << curr.bombsUsed << endl;
            break;
        }

        q.push({curr.row + 1, curr.col, curr.bombsUsed});
        q.push({curr.row - 1, curr.col, curr.bombsUsed});
        q.push({curr.row, curr.col + 1, curr.bombsUsed});
        q.push({curr.row, curr.col - 1, curr.bombsUsed});
    }

    return 0;
}