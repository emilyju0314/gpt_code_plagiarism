#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<char>> grid(n, vector<char>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int maxWhiteLines = 0;

    for(int i = 0; i < n; i++) {
        vector<int> countRows(n, 0);
        vector<int> countCols(n, 0);

        for(int h = 0; h < k; h++) {
            if(i + h >= n) {
                break;
            }

            for(int j = 0; j < k; j++) {
                if(grid[i+h][j] == 'B') {
                    countRows[i+h]++;
                }
                if(grid[j][i+h] == 'B') {
                    countCols[i+h]++;
                }
            }
        }

        int whiteLines = 0;

        for(int x : countRows) {
            if(x == 0) {
                whiteLines++;
            }
        }

        for(int x : countCols) {
            if(x == 0) {
                whiteLines++;
            }
        }

        maxWhiteLines = max(maxWhiteLines, whiteLines);
    }

    cout << maxWhiteLines << endl;

    return 0;
}