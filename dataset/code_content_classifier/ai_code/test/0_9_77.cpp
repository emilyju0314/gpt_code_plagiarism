#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int room_size = 0;

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    room_size++;
    
    int tile = grid[i][j];
    if (tile & 1) {
        dfs(i-1, j);
    }
    if (tile & 2) {
        dfs(i, j+1);
    }
    if (tile & 4) {
        dfs(i+1, j);
    }
    if (tile & 8) {
        dfs(i, j-1);
    }
}

int main() {
    cin >> n >> m;

    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> room_sizes;

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