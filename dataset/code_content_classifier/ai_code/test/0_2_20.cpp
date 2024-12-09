#include <iostream>
#include <vector>
using namespace std;

int countOperations(vector<vector<int>>& A, int n, int m) {
    int operations = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0 || j == m - 1) {
                if (A[i][j] == 0) operations++;
            } else {
                if (A[i][j] == 1) operations++;
            }
        }
    }
    return operations;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> A(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < m; j++) {
                A[i][j] = row[j] - '0';
            }
        }
        
        int operations = countOperations(A, n, m);
        cout << operations << endl;
    }
    
    return 0;
}