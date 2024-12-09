#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cell {
    int x, y, color;
};

int main() {
    int n;
    cin >> n;

    vector<Cell> cells(n);
    vector<vector<Cell>> cellsByColor(3);
    for (int i = 0; i < n; i++) {
        cin >> cells[i].x >> cells[i].y >> cells[i].color;
        cellsByColor[cells[i].color - 1].push_back(cells[i]);
    }

    int maxK = 0;
    for (int k = 3; k <= n; k += 3) {
        do {
            vector<Cell> chosenCells;
            for (int i = 0; i < 3; i++) {
                chosenCells.insert(chosenCells.end(), cellsByColor[i].begin(), cellsByColor[i].begin() + k/3);
            }

            vector<int> minX(3, 1e9), minY(3, 1e9);
            vector<int> maxX(3, -1), maxY(3, -1);

            for (const auto& cell : chosenCells) {
                int color = cell.color - 1;
                minX[color] = min(minX[color], cell.x);
                minY[color] = min(minY[color], cell.y);
                maxX[color] = max(maxX[color], cell.x);
                maxY[color] = max(maxY[color], cell.y);
            }

            bool validRectangles = true;
            for (int i = 0; i < 3; i++) {
                for (int j = i + 1; j < 3; j++) {
                    if ((minX[i] > maxX[j] || maxX[i] < minX[j]) && (minY[i] > maxY[j] || maxY[i] < minY[j])) {
                        validRectangles = false;
                        break;
                    }
                }
                if (!validRectangles) {
                    break;
                }
            }

            if (validRectangles) {
                maxK = k;
            }
        } while (next_permutation(cells.begin(), cells.end(), [](const Cell& lhs, const Cell& rhs) {
            return lhs.color < rhs.color;
        }));
    }

    cout << maxK << endl;

    return 0;
}