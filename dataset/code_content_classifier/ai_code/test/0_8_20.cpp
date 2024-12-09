#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        char grid[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        
        int count = 0;
        
        // check first row and last row
        for(int j = 1; j < m - 1; j++) {
            if(grid[0][j] == '0') count++;
            if(grid[n-1][j] == '0') count++;
        }
        
        // check first column and last column
        for(int i = 1; i < n - 1; i++) {
            if(grid[i][0] == '0') count++;
            if(grid[i][m-1] == '0') count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}