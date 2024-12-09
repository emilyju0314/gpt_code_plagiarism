#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // east, west, north, south

int main() {
    int H, W;
    
    while (cin >> H >> W && H != 0 && W != 0) {
        vector<string> room(H);
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        
        for (int i = 0; i < H; i++) {
            cin >> room[i];
        }
        
        int x = 0, y = 0;
        int direction = 0; // east
        
        while (x >= 0 && x < W && y >= 0 && y < H) {
            if (visited[y][x]) {
                cout << "LOOP" << endl;
                break;
            }
            
            visited[y][x] = true;
            
            char tile = room[y][x];
            if (tile == '.') {
                cout << x << " " << y << endl;
                break;
            } else if (tile == '>') {
                direction = 0; // east
            } else if (tile == '<') {
                direction = 1; // west
            } else if (tile == '^') {
                direction = 2; // north
            } else if (tile == 'v') {
                direction = 3; // south
            }
            
            x += directions[direction].first;
            y += directions[direction].second;
        }
    }
    
    return 0;
}