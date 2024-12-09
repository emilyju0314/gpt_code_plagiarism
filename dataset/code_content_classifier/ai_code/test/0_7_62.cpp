#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<bool>> matrix(n, vector<bool>(m, false));
    
    auto countStaircases = [&]() -> int {
        int staircases = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j]) {
                    if (i > 0 && j > 0 && matrix[i-1][j-1] && matrix[i-1][j] && matrix[i][j-1]) {
                        staircases++;
                    }
                    if (i > 0 && j < m - 1 && matrix[i-1][j+1] && matrix[i-1][j] && matrix[i][j+1]) {
                        staircases++;
                    }
                    if (i < n - 1 && j > 0 && matrix[i+1][j-1] && matrix[i+1][j] && matrix[i][j-1]) {
                        staircases++;
                    }
                    if (i < n - 1 && j < m - 1 && matrix[i+1][j+1] && matrix[i+1][j] && matrix[i][j+1]) {
                        staircases++;
                    }
                }
            }
        }
        return staircases;
    };

    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        matrix[x][y] = !matrix[x][y];
        cout << countStaircases() << endl;
    }

    return 0;
}