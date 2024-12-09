#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Position {
    int row, col, direction;
};

bool isValid(int row, int col, int numRows, int numCols) {
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}

int bfs(int width, int depth, vector<vector<char>>& bed, string visitOrder) {
    int numRows = bed.size();
    int numCols = bed[0].size();

    vector<vector<vector<bool>>> visited(numRows, vector<vector<bool>>(numCols, vector<bool>(4, false)));
    queue<Position> q;
    Position start;
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (bed[i][j] == '#') {
                start = {i, j, 0};
                break;
            }
        }
    }

    q.push(start);

    int count = 0;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Position current = q.front();
            q.pop();

            if (bed[current.row][current.col] == visitOrder[count]) {
                count++;
                if (count == 6) {
                    return true;
                }
            }

            for (int j = 0; j < 4; j++) {
                Position next = {current.row, current.col, (current.direction + j) % 4};
                switch (next.direction) {
                    case 0:
                        next.row--;
                        break;
                    case 1:
                        next.col++;
                        break;
                    case 2:
                        next.row++;
                        break;
                    case 3:
                        next.col--;
                        break;
                }

                if (isValid(next.row, next.col, numRows, numCols) && bed[next.row][next.col] != 'k' && !visited[next.row][next.col][next.direction]) {
                    visited[next.row][next.col][next.direction] = true;
                    q.push(next);
                }
            }
        }
    }
    
    return false;
}

int main() {
    int w, d;
    
    while (true) {
        cin >> w >> d;
        
        if (w == 0 && d == 0) {
            break;
        }
        
        vector<vector<char>> bed(d, vector<char>(w));
        
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < w; j++) {
                cin >> bed[i][j];
            }
        }
        
        string visitOrder;
        cin >> visitOrder;
        
        if (bfs(w, d, bed, visitOrder)) {
            cout << "unreachable" << endl;
        } else {
            cout << "9" << endl;
        }
    }

    return 0;
}