#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int eatenCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'W') {
                if (i - 1 >= 0 && grid[i - 1][j] == 'P') {
                    eatenCount++;
                } else if (i + 1 < n && grid[i + 1][j] == 'P') {
                    eatenCount++;
                } else if (j - 1 >= 0 && grid[i][j - 1] == 'P') {
                    eatenCount++;
                } else if (j + 1 < m && grid[i][j + 1] == 'P') {
                    eatenCount++;
                }
            }
        }
    }

    cout << eatenCount << endl;

    return 0;
}