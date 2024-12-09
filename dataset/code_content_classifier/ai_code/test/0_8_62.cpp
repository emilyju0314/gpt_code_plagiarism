#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m, q;
vector<vector<bool>> matrix;
set<int> staircases;

void countStaircases() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!matrix[i][j]) {
                if (i > 0 && !matrix[i - 1][j]) {
                    count++;
                }
                if (j > 0 && !matrix[i][j - 1]) {
                    count++;
                }
            }
        }
    }
    staircases.insert(count);
}

void toggleCell(int x, int y) {
    matrix[x][y] = !matrix[x][y];
}

int main() {
    cin >> n >> m >> q;
    matrix.resize(n, vector<bool>(m, false));

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        toggleCell(x, y);
        countStaircases();
        cout << staircases.size() << endl;
    }

    return 0;
}