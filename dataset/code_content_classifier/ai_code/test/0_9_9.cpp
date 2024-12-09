#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> balls(k);
    for(int i = 0; i < k; i++) {
        cin >> balls[i];
    }

    vector<int> result;
    for(int i = 0; i < k; i++) {
        int currentCol = balls[i];
        for(int j = 0; j < n; j++) {
            if(grid[j][currentCol-1] == 1) {
                currentCol++; // Move right
            } else if(grid[j][currentCol-1] == 2) {
                // Move down
            } else if(grid[j][currentCol-1] == 3) {
                currentCol--; // Move left
            }

            if(currentCol > 1 && currentCol <= m) {
                grid[j][currentCol-1] = 2; // Change direction
            }

            if(j == n-1) {
                result.push_back(currentCol);
            }
        }
    }

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}