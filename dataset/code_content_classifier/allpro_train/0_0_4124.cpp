#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> litCells;

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        litCells.push_back({r, c});
    }

    int minCoins = 0;
    int prevRow = 1, prevCol = 1;

    for (auto cell : litCells) {
        int r = cell.first, c = cell.second;

        if (r > prevRow || c > prevCol) {
            minCoins++;
            prevRow = r;
            prevCol = c;
        } else if (r < prevRow || c < prevCol) {
            cout << -1 << endl;
            return 0;
        }
    }

    if (prevRow != n || prevCol != m) {
        minCoins++;
    }

    cout << minCoins << endl;

    return 0;
}