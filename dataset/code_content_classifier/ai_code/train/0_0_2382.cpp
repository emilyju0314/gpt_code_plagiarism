#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> parkingLot(n, vector<int>(m));
    vector<pair<int, int>> carsCoordinates(k);
    
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            if (row[j] == '.') {
                parkingLot[i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        carsCoordinates[i] = make_pair(x-1, y-1);
        
        parkingLot[x-1][y-1] = 0;
        
        int maxSideLength = 0;
        
        for (int sideLength = 1; ; sideLength++) {
            bool canExpand = true;
            
            for (int dx = -sideLength+1; dx <= sideLength-1; dx++) {
                for (int dy = -sideLength+1; dy <= sideLength-1; dy++) {
                    int nx = x-1 + dx;
                    int ny = y-1 + dy;
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || parkingLot[nx][ny] == 0) {
                        canExpand = false;
                        break;
                    }
                }
                if (!canExpand) break;
            }
            
            if (!canExpand) break;
            
            maxSideLength = sideLength;
        }
        
        cout << maxSideLength << endl;
    }
    
    return 0;
}