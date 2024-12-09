#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while(true) {
        cin >> n;
        if (n == 0) break;

        vector<vector<int>> enemies(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> enemies[i][j];
            }
        }

        string spell = "";
        while (true) {
            bool allEnemiesDefeated = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (enemies[i][j] == 1) {
                        allEnemiesDefeated = false;
                        break;
                    }
                }
                if (!allEnemiesDefeated) break;
            }

            if (allEnemiesDefeated) break;

            int minRow = n, maxRow = -1, minCol = n, maxCol = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (enemies[i][j] == 1) {
                        minRow = min(minRow, i);
                        maxRow = max(maxRow, i);
                        minCol = min(minCol, j);
                        maxCol = max(maxCol, j);
                    }
                }
            }

            for (int i = minRow; i <= maxRow; i++) {
                for (int j = minCol; j <= maxCol; j++) {
                    enemies[i][j] = 0;
                }
            }

            int rowsAffected = maxRow - minRow + 1;
            int colsAffected = maxCol - minCol + 1;
            spell += "m";
            spell += string(rowsAffected*colsAffected, 'y');
            spell += "on";
        }

        cout << spell << endl;
    }

    return 0;
}