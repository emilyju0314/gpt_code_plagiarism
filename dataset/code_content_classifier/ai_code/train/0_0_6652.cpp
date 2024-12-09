#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<vector<int>> grid(n, vector<int>(n));

        // Read grid data
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                grid[i][j] = c - '0'; // Convert char to int
            }
        }

        // Compute the greatest number of consecutive 1s
        int maxConsecutiveOnes = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int count = 1;
                    
                    // Check right direction
                    for (int k = j + 1; k < n && grid[i][k] == 1; k++) {
                        count++;
                    }
                    maxConsecutiveOnes = max(maxConsecutiveOnes, count);
                    
                    count = 1;
                    // Check down direction
                    for (int k = i + 1; k < n && grid[k][j] == 1; k++) {
                        count++;
                    }
                    maxConsecutiveOnes = max(maxConsecutiveOnes, count);
                    
                    count = 1;
                    // Check diagonal down-right direction
                    for (int k = 1; i + k < n && j + k < n && grid[i + k][j + k] == 1; k++) {
                        count++;
                    }
                    maxConsecutiveOnes = max(maxConsecutiveOnes, count);
                    
                    count = 1;
                    // Check diagonal down-left direction
                    for (int k = 1; i + k < n && j - k >= 0 && grid[i + k][j - k] == 1; k++) {
                        count++;
                    }
                    maxConsecutiveOnes = max(maxConsecutiveOnes, count);
                }
            }
        }

        cout << maxConsecutiveOnes << endl;
    }

    return 0;
}