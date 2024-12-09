#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int H, W, K;
vector<vector<char>> grid;
vector<vector<vector<int>>> dist;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_valid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W && grid[x][y] != '#';
}

int main() {
    cin >> H >> W >> K;
    
    grid.resize(H, vector<char>(W));
    dist.resize(H, vector<vector<int>>(W, vector<int>(21, -1)));
    
    int start_x, start_y, end_x, end_y;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 's') {
                start_x = i;
                start_y = j;
            } else if (grid[i][j] == 'e') {
                end_x = i;
                end_y = j;
            }
        }
    }
    
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(start_x, start_y), 0));
    dist[start_x][start_y][0] = 0;
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int apples = q.front().second;
        q.pop();
        
        if (x == end_x && y == end_y && apples >= K) {
            cout << dist[x][y][apples] << endl;
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if (is_valid(new_x, new_y)) {
                int new_apples = apples;
                if (grid[new_x][new_y] == 'a') {
                    new_apples++;
                }
                
                if (new_apples <= K && dist[new_x][new_y][new_apples] == -1) {
                    dist[new_x][new_y][new_apples] = dist[x][y][apples] + 1;
                    q.push(make_pair(make_pair(new_x, new_y), new_apples));
                }
            }
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}