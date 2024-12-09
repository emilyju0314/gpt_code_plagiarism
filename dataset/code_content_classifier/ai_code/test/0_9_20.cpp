#include <iostream>
#include <vector>

using namespace std;

int minOperationsToMakePortal(vector<vector<int>>& A) {
    int n = A.size();
    int m = A[0].size();
    
    int minOperations = INT_MAX;
    
    for (int a = 5; a <= n; a++) {
        for (int b = 4; b <= m; b++) {
            int operations = 0;
            
            for (int i = 1; i < a - 1; i++) {
                for (int j = 1; j < b - 1; j++) {
                    if (A[i][j] == 1) {
                        operations++;
                    }
                }
            }
            
            minOperations = min(minOperations, operations);
        }
    }
    
    return minOperations;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> A(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                A[i][j] = c - '0';
            }
        }
        
        int result = minOperationsToMakePortal(A);
        cout << result << endl;
    }
    
    return 0;
}