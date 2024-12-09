#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }
    
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            matrix[i][j] = c - '0';
        }
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i == k || j == k) continue;
                if (matrix[i][k] && matrix[k][j]) {
                    matrix[i][j] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] && permutation[i] > permutation[j]) {
                swap(permutation[i], permutation[j]);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;
    
    return 0;
}