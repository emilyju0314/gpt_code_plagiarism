#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == n-1 && j == m-1) {
                    if (grid[i][j] != 'C') {
                        count++;
                    }
                } else {
                    if ((i == n-1 && grid[i][j] != 'R') || (j == m-1 && grid[i][j] != 'D')) {
                        count++;
                    }
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}