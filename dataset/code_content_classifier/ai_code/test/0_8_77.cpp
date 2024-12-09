#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> construction;
vector<vector<bool>> visited;
vector<int> roomSizes;

void dfs(int i, int j, int& size) {
    if (i < 0 || i >= N || j < 0 || j >= M || visited[i][j] || construction[i][j] == 0) {
        return;
    }

    visited[i][j] = true;
    size++;

    // Check northern tile
    if ((construction[i][j] & 1) == 0) {
        dfs(i - 1, j, size);
    }

    // Check eastern tile
    if ((construction[i][j] & 2) == 0) {
        dfs(i, j + 1, size);
    }

    // Check southern tile
    if ((construction[i][j] & 4) == 0) {
        dfs(i + 1, j, size);
    }

    // Check western tile
    if ((construction[i][j] & 8) == 0) {
        dfs(i, j - 1, size);
    }
}

int main() {
    cin >> N >> M;
    construction.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> construction[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                int size = 0;
                dfs(i, j, size);
                roomSizes.push_back(size);
            }
        }
    }

    sort(roomSizes.rbegin(), roomSizes.rend());

    for (int i = 0; i < roomSizes.size(); i++) {
        cout << roomSizes[i] << " ";
    }
    cout << endl;

    return 0;
}