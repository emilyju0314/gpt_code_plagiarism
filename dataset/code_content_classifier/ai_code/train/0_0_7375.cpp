#include <iostream>
#include <vector>

using namespace std;

bool checkTraining(int n, vector<vector<int>>& matrix) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1) {
                if(i < n - 1 && matrix[i+1][j] == 0 && j < n - 1 && matrix[i][j+1] == 0) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> matrix(n, vector<int>(n));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                char c;
                cin >> c;
                matrix[i][j] = c - '0';
            }
        }
        
        if(checkTraining(n, matrix)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}