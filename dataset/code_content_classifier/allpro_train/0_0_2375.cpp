#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 210;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char moves[] = {'U', 'D', 'R', 'L'};

bool isValid(int x, int y, int n, vector<pair<int, int>>& trees) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }
    for (pair<int, int> tree : trees) {
        if (tree.first == x && tree.second == y) {
            return false;
        }
    }
    return true;
}

int main() {
    int vx, vy, sx, sy, m;
    cin >> vx >> vy >> sx >> sy >> m;

    vector<pair<int, int>> trees;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        trees.push_back({x, y});
    }

    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));
    visited[vx][vy] = true;

    vector<pair<int, int>> q;
    vector<int> move_q;
    q.push_back({vx, vy});
    move_q.push_back(-1);

    bool found = false;
    string moves_to_catch = "";

    while (!q.empty() && !found) {
        pair<int, int> curr = q.back();
        q.pop_back();
        int move = move_q.back();
        move_q.pop_back();

        if (curr.first == sx && curr.second == sy) {
            found = true;
            while (move != -1) {
                moves_to_catch += moves[move];
                move = visited[curr.first][curr.second];
                curr.first -= dx[move];
                curr.second -= dy[move];
            }
            reverse(moves_to_catch.begin(), moves_to_catch.end());
            break;
        }

        for (int i = 0; i < 4; i++) {
            int new_x = curr.first + dx[i];
            int new_y = curr.second + dy[i];
            if (isValid(new_x, new_y, MAX, trees) && !visited[new_x][new_y]) {
                q.push_back({new_x, new_y});
                move_q.push_back(i);
                visited[new_x][new_y] = i;
            }
        }
    }

    if (found) {
        cout << moves_to_catch << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}