#include <iostream>
#include <vector>

using namespace std;

bool solve(int n, int m, int k) {
    if ((n * m) % 3 != 0) {
        return false;
    }
    
    vector<vector<char>> grid(n, vector<char>(m, '.'));
    int trominoCount = 0;
    
    for (int i = 0; i < n-1; i += 2) {
        for (int j = 0; j < m-1; j += 2) {
            if (trominoCount + 3 <= k) {
                grid[i][j] = '*';
                grid[i+1][j] = '*';
                grid[i][j+1] = '*';
                trominoCount += 3;
            }
        }
    }
    
    if (trominoCount != k) {
        return false;
    }
    
    cout << "Possible solution:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        if (!solve(n, m, k)) {
            cout << -1 << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}