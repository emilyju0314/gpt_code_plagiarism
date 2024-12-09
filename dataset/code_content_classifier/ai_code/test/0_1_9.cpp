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

    vector<int> result(k);

    for(int i = 0; i < k; i++) {
        int currentCol = columns[i];
        for(int j = 0; j < n; j++) {
            if(grid[j][currentCol-1] == 1) { // move to the right
                currentCol++;
            } else if(grid[j][currentCol-1] == 2) { // move downwards
                break;
            } else { // move to the left
                currentCol--;
            }
        }
        result[i] = currentCol;
    }

    for(int i = 0; i < k; i++) {
        cout << result[i] << " ";
    }

    return 0;
}