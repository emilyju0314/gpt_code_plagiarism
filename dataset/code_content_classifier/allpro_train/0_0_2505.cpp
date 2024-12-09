#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c, q;
    while (cin >> r >> c >> q) {
        vector<vector<int>> grid(r, vector<int>(c));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < q; i++) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;

            int lowestValue = INT32_MAX;
            for (int j = r1; j <= r2; j++) {
                for (int k = c1; k <= c2; k++) {
                    lowestValue = min(lowestValue, grid[j][k]);
                }
            }

            cout << lowestValue << endl;
        }
    }

    return 0;
}