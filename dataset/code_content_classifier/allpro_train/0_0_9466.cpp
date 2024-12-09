#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void vertical_xor(vector<vector<int>>& matrix, int j) {
    for(int i = 0; i < matrix.size(); i++) {
        matrix[i][j] ^= 1;
    }
}

void horizontal_xor(vector<vector<int>>& matrix, int i) {
    for(int j = 0; j < matrix.size(); j++) {
        matrix[i][j] ^= 1;
    }
}

bool canTransform(vector<vector<int>>& a, vector<vector<int>>& b) {
    int n = a.size();
    
    for(int i = 0; i < n; i++) {
        if(a[i][0] != b[i][0]) {
            horizontal_xor(a, i);
        }
    }
    
    for(int j = 0; j < n; j++) {
        if(a[0][j] != b[0][j]) {
            vertical_xor(a, j);
        }
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(a[i][j] != b[i][j]) {
                return false;
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
        
        vector<vector<int>> a(n, vector<int>(n));
        vector<vector<int>> b(n, vector<int>(n));
        
        for(int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for(int j = 0; j < n; j++) {
                a[i][j] = row[j] - '0';
            }
        }
        
        for(int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for(int j = 0; j < n; j++) {
                b[i][j] = row[j] - '0';
            }
        }
        
        if(canTransform(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}