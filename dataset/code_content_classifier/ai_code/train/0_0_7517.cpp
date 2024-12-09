#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
const char DIRS[] = "ESWN";

struct Person {
    int x, y, dir, step;
};

int W, H;
vector<string> maze;
vector<Person> people;

bool isInside(int x, int y) {
    return x >= 0 && x < W && y >= 0 && y < H;
}

bool isValidMove(int x, int y) {
    return isInside(x, y) && maze[y][x] != '#';
}

bool hasExit(int x, int y) {
    return isInside(x, y) && maze[y][x] == 'X';
}

int solve() {
    queue<Person> q;
    vector<vector<vector<vector<bool>>> > visited(W, vector<vector<vector<bool>>>(H, vector<vector<bool>>(4, vector<bool>(4, false))));

    for (Person p : people) {
        q.push(p);
        visited[p.x][p.y][p.dir][0] = true;
    }

    while (!q.empty()) {
        Person p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[p.dir];
            int ny = p.y + dy[p.dir];

            if (isValidMove(nx, ny) && !visited[nx][ny][p.dir][0]) {
                visited[nx][ny][p.dir][0] = true;
                q.push({nx, ny, p.dir, p.step + 1});

                if (hasExit(nx, ny)) {
                    return p.step + 1;
                }
            }

            int leftDir = (p.dir + 3) % 4;
            int rightDir = (p.dir + 1) % 4;

            if (!visited[p.x][p.y][leftDir][1]) {
                visited[p.x][p.y][leftDir][1] = true;
                q.push({p.x, p.y, leftDir, p.step + 1});
            }

            if (!visited[p.x][p.y][rightDir][1]) {
                visited[p.x][p.y][rightDir][1] = true;
                q.push({p.x, p.y, rightDir, p.step + 1});
            }
        }
    }

    return INF;
}

int main() {
    while (cin >> W >> H && W != 0 && H != 0) {
        maze.clear();
        people.clear();

        cin.ignore();

        for (int i = 0; i < H; i++) {
            string row;
            getline(cin, row);
            maze.push_back(row);

            for (int j = 0; j < W; j++) {
                char c = row[j];
                if (c != '.' && c != '#') {
                    int dir = strchr(DIRS, c) - DIRS;
                    people.push_back({j, i, dir, 0});
                }
            }
        }

        int result = solve();

        if (result >= INF) {
            cout << "NA" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}