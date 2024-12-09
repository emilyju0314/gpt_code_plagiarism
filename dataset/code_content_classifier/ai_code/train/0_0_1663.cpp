#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        vector<vector<int>> matrix(n, vector<int>(m, 0));
        
        if (n * a != m * b) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a; j++) {
                matrix[i][(i * a + j) % m] = 1;
            }
            
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}