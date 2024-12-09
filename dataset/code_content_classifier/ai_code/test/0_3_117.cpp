#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<char>> grid(n, vector<char>(m));
        
        pair<int, int> lab_pos;
        
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> grid[j][k];
                if (grid[j][k] == 'L') {
                    lab_pos = make_pair(j, k);
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (grid[j][k] == '.') {
                    if (j != lab_pos.first) {
                        grid[j][k] = '+';
                    } else if (k != lab_pos.second) {
                        grid[j][k] = '+';
                    }
                }
                cout << grid[j][k];
            }
            cout << endl;
        }
    }
    
    return 0;
}