#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> park(n);
    vector<vector<int>> spiders(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        cin >> park[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (park[i][j] != '.') {
                int row = i, col = j;
                for (int t = 0; t < k; t++) {
                    if (park[row][col] == 'L') {
                        col--;
                    } else if (park[row][col] == 'R') {
                        col++;
                    } else if (park[row][col] == 'U') {
                        row--;
                    } else if (park[row][col] == 'D') {
                        row++;
                    }

                    if (row == n) break;
                    if (row != 0) {
                        spiders[row][col]++;
                    }
                }
            }
        }
    }

    for (int j = 0; j < m; j++) {
        cout << spiders[0][j] << " ";
    }
    cout << endl;

    return 0;
}