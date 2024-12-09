#include <iostream>
#include <vector>

using namespace std;

bool isClearSymmetrical(vector<vector<int>>& A, int sharpness) {
    int n = A.size();
    
    // Check for symmetry
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(A[i][j] != A[n-1-i][j] || A[i][j] != A[i][n-1-j]) {
                return false;
            }
        }
    }
    
    // Check sharpness
    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(A[i][j] == 1) {
                count++;
            }
        }
    }
    
    return count == sharpness;
}

int main() {
    int x;
    cin >> x;
    
    int n = 1;
    while(true) {
        vector<vector<int>> A(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                A[i][j] = 1;
                if(isClearSymmetrical(A, x)) {
                    cout << n << endl;
                    return 0;
                }
                A[i][j] = 0;
            }
        }
        
        n++;
    }
    
    return 0;
}