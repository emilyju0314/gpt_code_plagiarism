#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
      
        // Input matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
      
        // Output matrix with increments
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i+j) % 2 == 0) {
                    cout << matrix[i][j] << " ";
                } else {
                    cout << matrix[i][j]+1 << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}