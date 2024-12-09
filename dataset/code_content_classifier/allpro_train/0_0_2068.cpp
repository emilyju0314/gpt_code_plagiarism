#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;

struct State {
    int x, y, t;
};

int H, W;
char grid[20][20];
string pattern;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W && grid[x][y] != '#';
}

int bfs() {
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(10, INF)));
    queue<State> q;
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(grid[i][j] == 'A') {
                q.push({i, j, 0});
                dist[i][j][0] = 0;
            }
        }
    }
    
    while(!q.empty()) {
        State s = q.front();
        q.pop();
        
        if(grid[s.x][s.y] == 'B') {
            return s.t;
        }
        
        for(int k = 0; k < 4; k++) {
            int nx = s.x + dx[k];
            int ny = s.y + dy[k];
            int nt = (s.t + 1) % pattern.size();
            
            if(isValid(nx, ny) && dist[nx][ny][nt] == INF) {
                dist[nx][ny][nt] = s.t + 1;
                q.push({nx, ny, s.t + 1});
            }
        }
    }
    
    return -1;
}

int main() {
    while(true) {
        cin >> H >> W;
        if(H == 0 && W == 0) break;
        
        memset(grid, 0, sizeof(grid));
        
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> grid[i][j];
            }
        }
        
        cin >> pattern;
        
        int res = bfs();
        
        if(res != -1) {
            cout << res << " ";
            for(int i = 0; i < H; i++) {
                for(int j = 0; j < W; j++) {
                    if(grid[i][j] == 'B') {
                        cout << i << " " << j << "\n";
                    }
                }
            }
        } else {
            cout << "impossible\n";
        }
    }
    
    return 0;
}