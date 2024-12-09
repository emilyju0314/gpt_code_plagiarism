#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        // Minimum possible value of f(A) is always 0
        cout << "0\n";

        // Construct the grid A
        vector<vector<int>> grid(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(k > 0) {
                    grid[i][j] = 1;
                    k--;
                }
            }
        }

        // Output the grid A
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}