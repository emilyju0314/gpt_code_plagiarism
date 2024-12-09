#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int H, W, N;
    
    while (true) {
        cin >> H >> W >> N;
        if (H == 0 && W == 0 && N == 0) {
            break;
        }
        
        string commands;
        cin >> commands;
        
        vector<vector<char>> maze(H, vector<char>(W));
        Point start, end;
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> maze[i][j];
                if (maze[i][j] == 'S') {
                    start = {i, j};
                }
                if (maze[i][j] == 'G') {
                    end = {i, j};
                }
            }
        }
        
        Point robot = start;
        int direction = 0; // 0 - north, 1 - east, 2 - south, 3 - west
        
        for (int i = 0; i < N; i++) {
            if (commands[i] == 'L') {
                direction = (direction + 3) % 4;
            } else if (commands[i] == 'R') {
                direction = (direction + 1) % 4;
            }
            Point next = robot;
            
            if (direction == 0) { // north
                next.x--;
            } else if (direction == 1) { // east
                next.y++;
            } else if (direction == 2) { // south
                next.x++;
            } else if (direction == 3) { // west
                next.y--;
            }
            
            if (next.x < 0 || next.x >= H || next.y < 0 || next.y >= W || maze[next.x][next.y] == '#') {
                continue;
            }
            
            robot = next;
        }
        
        if (robot.x == end.x && robot.y == end.y) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}