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
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        
        bool found = false;
        for(int i = 0; i < n; i++) {
            bool allRed = true, allBlue = true;
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] <= matrix[i][j-1]) {
                    allRed = false;
                }
                if(matrix[i][j] >= matrix[i][j-1]) {
                    allBlue = false;
                }
            }
            
            if(!allRed && !allBlue) {
                found = true;
                cout << "YES" << endl;
                
                for(int k = 0; k < n; k++) {
                    if(k % 2 == 0) {
                        cout << "R";
                    } else {
                        cout << "B";
                    }
                }
                cout << endl;
                
                cout << "1" << endl;
                break;
            }
        }
        
        if(!found) {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}