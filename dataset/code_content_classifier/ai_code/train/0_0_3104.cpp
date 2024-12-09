#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool is_solvable(int h, int w, vector<string>& grid, int n, string characters) {
    // Count number of blank cells in the grid
    int blank_cells = 0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(grid[i][j] == '.') {
                blank_cells++;
            }
        }
    }
    
    // Check if number of blank cells is equal to the number of characters
    if(blank_cells != n) {
        return false;
    }
    
    // Check if the grid is solvable
    // Implement your logic here
    
    return true;
}

int main() {
    int h, w, n;
    
    while(true) {
        cin >> h >> w;
        if(h == 0 && w == 0) {
            break;
        }
        
        vector<string> grid(h);
        for(int i=0; i<h; i++) {
            cin >> grid[i];
        }
        
        cin >> n;
        string characters;
        cin >> characters;
        
        if(is_solvable(h, w, grid, n, characters)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}