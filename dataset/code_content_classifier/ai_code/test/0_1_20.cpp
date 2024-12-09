#include <iostream>
#include <vector>
using namespace std;

int minOperationsToMakePortal(vector<vector<int>>& A, int n, int m) {
    int totalOps = 0;
    
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (A[i][j] == 0) {
                totalOps++;
            }
        }
    }
    
    return totalOps;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> A(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                A[i][j] = c -'0';
            }
        }
        
        int minOps = minOperationsToMakePortal(A, n, m);
        cout << minOps << endl;
    }
    
    return 0;
}