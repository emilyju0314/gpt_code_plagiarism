#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int H, W, N;
        cin >> H >> W >> N;
        
        if (H == 0 && W == 0 && N == 0) {
            break;
        }
        
        vector<vector<int>> grid(H, vector<int>(W));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> grid[i][j];
            }
        }
        
        int direction = 0; // 0 for east, 1 for south
        int i = 0, j = 0;
        while (N > 0) {
            if (i == H || j == W) {
                break;
            }
            if (grid[i][j] == 0) {
                direction = 1 - direction;
            }
            if (direction == 0) {
                j++;
            } else {
                i++;
            }
            N--;
        }
        
        cout << i << " " << j << endl;
    }
    
    return 0;
}