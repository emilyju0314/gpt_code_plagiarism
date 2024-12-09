#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int count = 0;
        for (int i = 0; i < (n + m) / 2; i++) {
            int ones = 0, zeroes = 0;
            for (int j = 0; j < 4; j++) {
                int x = i - j, y = (n + m - 2) - i + j;
                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if (matrix[x][j] == 1)
                    ones++;
                else
                    zeroes++;
                if (x != y) {
                    if (matrix[y][i - j] == 1)
                        ones++;
                    else
                        zeroes++;
                }
            }
            count += min(ones, zeroes);
        }

        cout << count << endl;
    }

    return 0;
}