#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<int> enemiesInRow(H, 0);
    vector<int> enemiesInCol(W, 0);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        enemiesInRow[y]++;
        enemiesInCol[x]++;
    }

    int maxEnemiesInRow = *max_element(enemiesInRow.begin(), enemiesInRow.end());
    int maxEnemiesInCol = *max_element(enemiesInCol.begin(), enemiesInCol.end());

    int cost = maxEnemiesInRow + maxEnemiesInCol;

    cout << cost << endl;

    return 0;
}