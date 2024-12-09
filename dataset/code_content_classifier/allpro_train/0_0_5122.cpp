#include <iostream>
#include <vector>

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
        
        bool possible = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O') {
                    int count = 0;
                    if (i > 0 && grid[i - 1][j] == 'O') count++;
                    if (i < n - 1 && grid[i + 1][j] == 'O') count++;
                    if (j > 0 && grid[i][j - 1] == 'O') count++;
                    if (j < m - 1 && grid[i][j + 1] == 'O') count++;
                    
                    if (count != 1) {
                        possible = false;
                        break;
                    }
                }
            }
        }
        
        if (!possible) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < 2 * n - 1; i++) {
                for (int j = 0; j < 2 * m - 1; j++) {
                    if (i % 2 == 0 && j % 2 == 0) {
                        cout << (grid[i / 2][j / 2] == 'O' ? 'O' : 'X');
                    } else if (i % 2 == 0) {
                        cout << (grid[i / 2][j / 2] == 'O' ? ' ' : 'X');
                    } else if (j % 2 == 0) {
                        cout << (grid[i / 2][j / 2] == 'O' ? ' ' : 'X');
                    } else {
                        cout << ' ';
                    }
                }
                cout << endl;
            }
        }
    }
    
    return 0;
}