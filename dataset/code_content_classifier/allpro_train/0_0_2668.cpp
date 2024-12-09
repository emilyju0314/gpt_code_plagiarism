#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2000;
const int MAX_M = 2000;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
int num_components = 0;

void dfs(int x, int y) {
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        
        if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && grid[new_x][new_y] == 1 && !visited[new_x][new_y]) {
            dfs(new_x, new_y);
        }
    }
}

int count_connected_components(int x1, int y1, int x2, int y2) {
    visited.assign(N, vector<bool>(M, false));
    num_components = 0;
    
    for (int i = x1 - 1; i < x2; i++) {
        for (int j = y1 - 1; j < y2; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                num_components++;
                dfs(i, j);
            }
        }
    }
    
    return num_components;
}

int main() {
    cin >> N >> M;
    
    grid.resize(N, vector<int>(M));
    
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            grid[i][j] = row[j] - '0';
        }
    }
    
    int Q;
    cin >> Q;
    
    for (int q = 0; q < Q; q++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << count_connected_components(x1, y1, x2, y2) << endl;
    }
    
    return 0;
}