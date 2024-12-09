#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<bool>> matrix(n, vector<bool>(m, false));
    set<pair<int, int>> affectedCells;
    int differentStaircases = 0;

    auto countStaircases = [&](int i, int j) {
        int staircases = 0;
        for (int x = i - 1; x <= i + 1; x++) {
            if (x < 0 || x >= n) continue;
            for (int y = j - 1; y <= j + 1; y++) {
                if (y < 0 || y >= m) continue;
                if (matrix[x][y]) continue;
                if (affectedCells.find({ x, y }) != affectedCells.end()) continue;

                staircases++;
            }
        }
        return staircases;
    };

    for (int k = 0; k < q; k++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        differentStaircases -= countStaircases(x, y);
        matrix[x][y] = !matrix[x][y];
        differentStaircases += countStaircases(x, y);

        affectedCells.insert({ x, y });
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newX = x + i, newY = y + j;
                if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
                if (i == 0 && j == 0) continue;
                if (affectedCells.find({ newX, newY }) == affectedCells.end()) continue;

                differentStaircases -= countStaircases(newX, newY);
                affectedCells.erase({ newX, newY });
            }
        }

        cout << differentStaircases << endl;
    }

    return 0;
}