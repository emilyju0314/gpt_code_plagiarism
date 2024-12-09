#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> construction;
vector<vector<bool>> visited;
int roomSize = 0;

int bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    roomSize = 1;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        if (x > 0 && !visited[x-1][y] && !(construction[x][y] & 1)) {
            q.push({x-1, y});
            visited[x-1][y] = true;
            roomSize++;
        }
        if (y < M-1 && !visited[x][y+1] && !(construction[x][y] & 2)) {
            q.push({x, y+1});
            visited[x][y+1] = true;
            roomSize++;
        }
        if (x < N-1 && !visited[x+1][y] && !(construction[x][y] & 4)) {
            q.push({x+1, y});
            visited[x+1][y] = true;
            roomSize++;
        }
        if (y > 0 && !visited[x][y-1] && !(construction[x][y] & 8)) {
            q.push({x, y-1});
            visited[x][y-1] = true;
            roomSize++;
        }
    }

    return roomSize;
}

int main() {
    cin >> N >> M;
    construction.resize(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> construction[i][j];
        }
    }

    vector<int> roomSizes;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                roomSizes.push_back(bfs(i, j));
            }
        }
    }

    sort(roomSizes.rbegin(), roomSizes.rend());

    for (int size : roomSizes) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}