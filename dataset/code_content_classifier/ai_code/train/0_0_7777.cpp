#include <iostream>
#include <string>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    
    string snuke = "snuke";
    string grid[H][W];
    
    // Input grid values
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == snuke) {
                cout << char('A' + j) << i+1 << endl;
                return 0; // Stop after finding the snuke
            }
        }
    }
    
    return 0;
}