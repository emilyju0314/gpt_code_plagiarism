#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> construction;
vector<vector<bool>> visited;
int room_size = 0;

void dfs(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M) {
        return;
    }
    if (visited[i][j] || construction[i][j] == 0) {
        return;
    }
    visited[i][j] = true;
    room_size++;
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
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

    vector<int> room_sizes;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
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