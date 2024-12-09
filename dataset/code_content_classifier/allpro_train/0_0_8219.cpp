#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canCollectTreasure(int N, int M, vector<string>& grid) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    int reachableRooms = 1;
    bool hasChest1 = false, hasChest2 = false, hasChest3 = false;
    
    int currentRow = 0, currentCol = 0;
    
    while(reachableRooms > 0) {
        visited[currentRow][currentCol] = true;
        reachableRooms--;
        
        if(grid[currentRow][currentCol] == '1') {
            hasChest1 = true;
        } else if(grid[currentRow][currentCol] == '2') {
            hasChest2 = true;
        } else if(grid[currentRow][currentCol] == '3') {
            hasChest3 = true;
        }
        
        if(hasChest1 && hasChest2 && hasChest3 && currentRow == 0 && currentCol == 0) {
            return true;
        }
        
        if(currentRow > 0 && grid[currentRow-1][currentCol] != '#' && !visited[currentRow-1][currentCol]) {
            reachableRooms++;
            currentRow--;
        } else if(currentRow < N-1 && grid[currentRow+1][currentCol] != '#' && !visited[currentRow+1][currentCol]) {
            reachableRooms++;
            currentRow++;
        } else if(currentCol > 0 && grid[currentRow][currentCol-1] != '#' && !visited[currentRow][currentCol-1]) {
            reachableRooms++;
            currentCol--;
        } else if(currentCol < M-1 && grid[currentRow][currentCol+1] != '#' && !visited[currentRow][currentCol+1]) {
            reachableRooms++;
            currentCol++;
        } else {
            break;
        }
    }
    
    return false;
}

int main() {
    int N, M;
    
    while(true) {
        cin >> N >> M;
        
        if(N == 0 && M == 0) {
            break;
        }
        
        vector<string> grid(N);
        for(int i = 0; i < N; i++) {
            cin >> grid[i];
        }
        
        if(canCollectTreasure(N, M, grid)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}