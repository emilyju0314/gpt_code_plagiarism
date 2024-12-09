#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    if (k > n*n)
        cout << -1 << endl;
    else {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n && k > 0; i++) {
            matrix[i][i] = 1;
            k--;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n && k > 1; j++) {
                matrix[i][j] = 1;
                matrix[j][i] = 1;
                k -= 2;
            }
        }
        
        if (k > 0)
            cout << -1 << endl;
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    
    return 0;
}