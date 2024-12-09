#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int max_val = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > max_val) {
            max_val = a[i];
        }
    }
    
    vector<vector<char>> grid(max_val, vector<char>(n*3, ' '));
    
    for(int i = 0; i < max_val; i++) {
        int x = 0;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < a[j]; k++) {
                if(i == k) {
                    grid[i][x] = '/';
                }
                if(i == a[j] - k - 1) {
                    grid[i][x+2] = '\\';
                }
                x += 3;
            }
        }
    }
    
    for(int i = max_val - 1; i >= 0; i--) {
        for(int j = 0; j < n*3; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    return 0;
}