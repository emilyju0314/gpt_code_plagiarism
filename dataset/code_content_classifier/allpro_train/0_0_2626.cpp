#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n*n);
    for(int i = 0; i < n*n; i++) {
        cin >> a[i];
    }

    // Sort the input numbers
    sort(a.begin(), a.end());

    // Calculate the target sum
    int s = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
    }
    
    // Print the target sum
    cout << s << endl;
    
    // Initialize the magic square as a 2D vector
    vector<vector<int>> magic_square(n, vector<int>(n, 0));
    
    // Fill the magic square with the sorted input numbers
    int row = 0, col = n/2;
    for(int i = 0; i < n*n; i++) {
        magic_square[row][col] = a[i];
        row--;
        col++;
        if(row == -1 && col == n) {
            row = 1;
            col = n - 1;
        } else if(row == -1) {
            row = n - 1;
        } else if(col == n) {
            col = 0;
        }
    }

    // Print the magic square
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << magic_square[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}