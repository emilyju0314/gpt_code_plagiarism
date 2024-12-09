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

    vector<int> columns(k);
    for(int i = 0; i < k; i++) {
        cin >> columns[i];
    }

    for(int i = 0; i < k; i++) {
        int currCol = columns[i];
        int row = 0;
        while(row < n) {
            if(grid[row][currCol-1] == 1) {
                currCol += 1;
            } else if(grid[row][currCol-1] == 2) {
                row += 1;
            } else if(grid[row][currCol-1] == 3) {
                currCol -= 1;
            }

            if(currCol == 0 || currCol == m+1) {
                break;
            }
        }
        cout << currCol << " ";
    }

    return 0;
}