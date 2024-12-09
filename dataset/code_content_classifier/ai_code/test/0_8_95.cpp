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
        
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        
        bool red = true, blue = true;
        string colors(n, 'R');
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] <= matrix[i][0]) {
                    colors[i] = 'B';
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            if (colors[i] != colors[0]) {
                red = false;
                blue = false;
                break;
            }
        }
        
        if (red || blue) {
            cout << "NO" << endl;
            continue;
        }
        
        int k = 0;
        while (k < m - 1 && colors[0] == colors[n - 1]) {
            if (matrix[0][k] <= matrix[n - 1][k]) {
                break;
            }
            k++;
        }
        
        if (k == m - 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << colors << " " << k + 1 << endl;
        }
    }
    
    return 0;
}