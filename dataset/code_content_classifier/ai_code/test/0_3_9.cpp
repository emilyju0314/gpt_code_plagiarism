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
        int col = columns[i];
        int row = 0;

        while(row < n) {
            if(grid[row][col-1] == 1) {
                col++;
            }
            else if(grid[row][col-1] == 3) {
                col--;
            }
            row++;
        }

        cout << col << " ";
    }

    return 0;
}