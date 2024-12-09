#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State {
    int x, y, dir, dist;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    pair<int, int> start;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '^' || grid[i][j] == 'v' || grid[i][j] == '<' || grid[i][j] == '>') {
                start = {i, j};
            }
        }
    }

    vector<vector<vector<vector<int>>>> visited(N, vector<vector<vector<int>>>(M, vector<vector<int>>(4, vector<int>(4, false)));

    queue<State> q;
    q.push({start.first, start.second, 0, 0});
    q.push({start.first, start.second, 1, 0});
    q.push({start.first, start.second, 2, 0});
    q.push({start.first, start.second, 3, 0});

    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (grid[curr.x][curr.y] == 'G') {
            cout << curr.dist << endl;
            return 0;
        }

        if (visited[curr.x][curr.y][curr.dir][curr.dist % 4]) {
            continue;
        }
        visited[curr.x][curr.y][curr.dir][curr.dist % 4] = true;

        int nx = curr.x + dx[curr.dir];
        int ny = curr.y + dy[curr.dir];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] != '#') {
            q.push({nx, ny, curr.dir, curr.dist + 1});
        } else {
            q.push({curr.x, curr.y, (curr.dir + 1) % 4, curr.dist + 1});
            q.push({curr.x, curr.y, (curr.dir + 3) % 4, curr.dist + 1});
        }
    }

    cout << -1 << endl;

    return 0;
}