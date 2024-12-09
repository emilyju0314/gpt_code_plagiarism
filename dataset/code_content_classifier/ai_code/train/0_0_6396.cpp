#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct State {
    vector<vector<char>> board;
    int emptyX, emptyY;
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
    int x, y;
    
    while (cin >> x >> y) {
        if (x == 0 && y == 0) {
            break;
        }
        
        State start;
        start.board.resize(3, vector<char>(3));
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> start.board[i][j];
                if (start.board[i][j] == 'E') {
                    start.emptyX = i;
                    start.emptyY = j;
                }
            }
        }
        
        string target[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> target[i][j];
            }
        }
        
        queue<State> q;
        q.push(start);
        
        map<vector<vector<char>>, int> dist;
        dist[start.board] = 0;
        
        int ans = -1;
        
        while (!q.empty()) {
            State cur = q.front();
            q.pop();
            
            if (cur.board[0][0] == target[0][0] && cur.board[0][1] == target[0][1] && cur.board[0][2] == target[0][2]
                && cur.board[1][0] == target[1][0] && cur.board[1][1] == target[1][1] && cur.board[1][2] == target[1][2]
                && cur.board[2][0] == target[2][0] && cur.board[2][1] == target[2][1] && cur.board[2][2] == target[2][2]) {
                ans = dist[cur.board];
                break;
            }
            
            for (int i = 0; i < 4; i++) {
                int newX = cur.emptyX + dx[i];
                int newY = cur.emptyY + dy[i];
                
                if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3) {
                    State next = cur;
                    swap(next.board[cur.emptyX][cur.emptyY], next.board[newX][newY]);
                    next.emptyX = newX;
                    next.emptyY = newY;
                    
                    if (dist.count(next.board) == 0) {
                        dist[next.board] = dist[cur.board] + 1;
                        q.push(next);
                    }
                }
            }
        }
        
        if (ans <= 30) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}