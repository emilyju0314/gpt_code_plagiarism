#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;

struct Point {
    int x;
    int y;
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    int W, H;
    
    while (true) {
        cin >> W >> H;
        
        if (W == 0 && H == 0) {
            break;
        }
        
        vector<string> grid(H);
        Point start;
        
        for (int i = 0; i < H; i++) {
            cin >> grid[i];
            
            for (int j = 0; j < W; j++) {
                if (grid[i][j] == 'S') {
                    start.x = j;
                    start.y = i;
                }
            }
        }
        
        int ansAttribute = -1;
        int ansMoves = INF;
        
        for (int i = 1; i <= 5; i++) {
            int moves[6][6];
            memset(moves, -1, sizeof(moves));
            
            moves[i][i] = 0;
            
            queue<Point> q;
            q.push(start);
            
            while (!q.empty()) {
                Point curr = q.front();
                q.pop();
                
                for (int j = 0; j < 4; j++) {
                    int nx = curr.x + dx[j];
                    int ny = curr.y + dy[j];
                    
                    if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
                        int currAttr = grid[curr.y][curr.x] - '0';
                        int nextAttr = grid[ny][nx] - '0';
                        
                        if ((moves[currAttr][nextAttr] == -1 || moves[currAttr][nextAttr] > moves[currAttr][currAttr] + 1) && moves[currAttr][currAttr] != -1) {
                            moves[currAttr][nextAttr] = moves[currAttr][currAttr] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            
            int minMoves = INF;
            
            for (int j = 1; j <= 5; j++) {
                if (j == i) {
                    continue;
                }
                
                if (moves[i][j] != -1 && moves[j][i] != -1) {
                    minMoves = min(minMoves, moves[i][j] + moves[j][i]);
                }
            }
            
            if (minMoves < ansMoves) {
                ansAttribute = i;
                ansMoves = minMoves;
            }
        }
        
        if (ansMoves == INF) {
            cout << "NA" << endl;
        } else {
            cout << ansAttribute << " " << ansMoves << endl;
        }
    }
    
    return 0;
}