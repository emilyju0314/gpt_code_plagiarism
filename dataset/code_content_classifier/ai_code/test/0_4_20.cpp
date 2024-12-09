#include <iostream>
#include <vector>

using namespace std;

int minOperationsToPortal(int n, int m, vector<vector<char>>& A) {
    int operations = 0;
    for (int i = 1; i < n-1; i++) {
        if (A[i][1] == '0') {
            A[i][1] = '1';
            operations++;
        }
        if (A[i][m-2] == '0') {
            A[i][m-2] = '1';
            operations++;
        }
    }
    
    for (int i = 1; i < m-1; i++) {
        if (A[1][i] == '0') {
            A[1][i] = '1';
            operations++;
        }
        if (A[n-2][i] == '0') {
            A[n-2][i] = '1';
            operations++;
        }
    }
    
    return operations;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<char>> A(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }
        
        int operations = minOperationsToPortal(n, m, A);
        cout << operations << endl;
    }
    
    return 0;
}