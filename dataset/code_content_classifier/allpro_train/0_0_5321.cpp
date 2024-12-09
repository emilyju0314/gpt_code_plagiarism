#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> painting(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> painting[i][j];
        }
    }
    
    int minArea = 1000; // Initialize to a large value
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(painting[i][j] == 'X') {
                int minX = i, minY = j, maxX = i, maxY = j;
                
                // Find the boundaries of the altered area
                while(maxX < n && painting[maxX][j] == 'X') maxX++;
                while(maxY < m && painting[i][maxY] == 'X') maxY++;
                
                // Calculate the area of the brush
                int area = (maxX - minX) * (maxY - minY);
                if(area < minArea) minArea = area;
                
                // Reset the cells to avoid double counting
                for(int x = minX; x < maxX; x++) {
                    for(int y = minY; y < maxY; y++) {
                        painting[x][y] = '.';
                    }
                }
            }
        }
    }
    
    // Check if all altered cells were covered
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(painting[i][j] == 'X') {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    cout << minArea << endl;
    
    return 0;
}