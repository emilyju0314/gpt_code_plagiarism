#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<int> roomSizes;

int dfs(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) {
        return 0;
    }

    visited[i][j] = true;
    int size = 1;

    if(!(grid[i][j] & 1)) {
        size += dfs(i-1, j);
    }
    if(!(grid[i][j] & 2)) {
        size += dfs(i, j+1);
    }
    if(!(grid[i][j] & 4)) {
        size += dfs(i+1, j);
    }
    if(!(grid[i][j] & 8)) {
        size += dfs(i, j-1);
    }

    return size;
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                roomSizes.push_back(dfs(i, j));
            }
        }
    }

    sort(roomSizes.rbegin(), roomSizes.rend());

    for(int size : roomSizes) {
        cout << size << " ";
    }

    return 0;
}