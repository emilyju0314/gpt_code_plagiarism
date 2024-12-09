#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minOperationsToMakePortal(vector<vector<char>>& A) {
    int n = A.size();
    int m = A[0].size();
    
    int ans = INT_MAX;
    
    for (int i = 0; i < n-4; i++) {
        for (int j = 0; j < m-3; j++) {
            int currOperations = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if ((x > i && x < i + 5 && (y == 0 || y == m-1)) || (y > j && y < j + 4 && (x == 0 || x == n-1))) {
                        if (A[x][y] == '0') currOperations++;
                    } else if (x > i && x < i + 5 && y > j && y < j + 4) {
                        if (A[x][y] == '1') currOperations++;
                    }
                }
            }
            ans = min(ans, currOperations);
        }
    }
    
    return ans;
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
        
        int result = minOperationsToMakePortal(A);
        cout << result << endl;
    }
    
    return 0;
}