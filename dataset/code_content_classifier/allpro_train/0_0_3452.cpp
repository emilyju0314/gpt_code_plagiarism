#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int bfs(vector<vector<int>>& board, int startX, int startY, int width, int height) {
    vector<vector<int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<tuple<int, int, int>> q;
    q.push({startX, startY, 0});
    
    while (!q.empty()) {
        int x, y, dist;
        tie(x, y, dist) = q.front();
        q.pop();
        
        if (board[y][x] == 3) {
            return dist;
        }
        
        for (auto& move : moves) {
            int newX = x + move[0];
            int newY = y + move[1];
            
            if (newX >= 0 && newX < width && newY >= 0 && newY < height && board[newY][newX] != 1) {
                q.push({newX, newY, dist + 1});
                board[newY][newX] = 1;
            }
        }
    }
    
    return -1;
}

int main() {
    int w, h;
    
    while (true) {
        cin >> w >> h;
        
        if (w == 0 && h == 0) {
            break;
        }
        
        vector<vector<int>> board(h, vector<int>(w));
        int startX, startY;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
                if (board[i][j] == 2) {
                    startX = j;
                    startY = i;
                }
            }
        }
        
        int minMoves = bfs(board, startX, startY, w, h);
        cout << minMoves << endl;
    }
    
    return 0;
}