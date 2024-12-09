#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000009;

int main() {
    int W, H, N;
    int grid[76][100002];
    int obstacles[31][2];
    int caseNum = 1;
    
    while (true) {
        cin >> W >> H >> N;
        if (W == 0 && H == 0 && N == 0) {
            break;
        }
        
        memset(grid, 0, sizeof(grid));
        for (int i = 0; i < N; i++) {
            cin >> obstacles[i][0] >> obstacles[i][1];
        }
        
        grid[1][1] = 1;
        for (int y = 1; y <= H; y++) {
            for (int x = 1; x <= W; x++) {
                if (grid[x][y] == 0) {
                    continue;
                }
                for (int i = 0; i < N; i++) {
                    if (obstacles[i][0] == x && obstacles[i][1] == y) {
                        grid[x][y] = 0;
                        break;
                    }
                }
                
                if (grid[x][y] != 0) {
                    if (x + 1 <= W) {
                        grid[x + 1][y + 1] = (grid[x + 1][y + 1] + grid[x][y]) % MOD;
                    }
                    if (x - 1 >= 1) {
                        grid[x - 1][y + 1] = (grid[x - 1][y + 1] + grid[x][y]) % MOD;
                    }
                    grid[x][y + 1] = (grid[x][y + 1] + grid[x][y]) % MOD;
                }
            }
        }
        
        cout << "Case " << caseNum << ": " << grid[W][H] << endl;
        caseNum++;
    }
    
    return 0;
}