#include <iostream>
#include <vector>

using namespace std;

int countReachableTiles(vector<vector<char>>& tiles, int x, int y) {
    if (x < 0 || x >= tiles.size() || y < 0 || y >= tiles[0].size() || tiles[x][y] == '#' || tiles[x][y] == 'X') {
        return 0;
    }
    
    int count = 1;
    tiles[x][y] = 'X'; // Mark as visited
    
    count += countReachableTiles(tiles, x+1, y); // Down
    count += countReachableTiles(tiles, x-1, y); // Up
    count += countReachableTiles(tiles, x, y+1); // Right
    count += countReachableTiles(tiles, x, y-1); // Left
    
    return count;
}

int main() {
    int W, H;
    
    while (true) {
        cin >> W >> H;
        
        if (W == 0 && H == 0) {
            break;
        }
        
        vector<vector<char>> tiles(H, vector<char>(W));
        int startX = 0;
        int startY = 0;
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> tiles[i][j];
                if (tiles[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
            }
        }
        
        int count = countReachableTiles(tiles, startX, startY);
        cout << count << endl;
    }
    
    return 0;
}