#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> construction;
vector<vector<bool>> visited;
vector<int> room_sizes;
int room_size;

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) {
        return;
    }

    visited[i][j] = true;
    room_size++;

    int tile = construction[i][j];
    // Check if there is a wall on each side
    if (!(tile & 1)) {
        dfs(i, j - 1);
    }
    if (!(tile & 2)) {
        dfs(i - 1, j);
    }
    if (!(tile & 4)) {
        dfs(i, j + 1);
    }
    if (!(tile & 8)) {
        dfs(i + 1, j);
    }
}

int main() {
    cin >> n >> m;

    construction.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tile;
            cin >> tile;
            construction[i].push_back(tile);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                room_size = 0;
                dfs(i, j);
                room_sizes.push_back(room_size);
            }
        }
    }

    sort(room_sizes.rbegin(), room_sizes.rend());

    for (int size : room_sizes) {
        cout << size << " ";
    }

    return 0;
}