#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int d, w;
        cin >> d >> w;
        if (d == 0 && w == 0) {
            break;
        }

        vector<vector<int>> garden(d, vector<int>(w));
        vector<vector<int>> left(d, vector<int>(w));
        vector<vector<int>> right(d, vector<int>(w));
        vector<vector<int>> up(d, vector<int>(w));
        vector<vector<int>> down(d, vector<int>(w));

        for (int i = 0; i < d; i++) {
            for (int j = 0; j < w; j++) {
                cin >> garden[i][j];
            }
        }

        // Calculate left boundary
        for (int i = 0; i < d; i++) {
            left[i][0] = garden[i][0];
            for (int j = 1; j < w; j++) {
                left[i][j] = max(left[i][j - 1], garden[i][j]);
            }
        }

        // Calculate right boundary
        for (int i = 0; i < d; i++) {
            right[i][w - 1] = garden[i][w - 1];
            for (int j = w - 2; j >= 0; j--) {
                right[i][j] = max(right[i][j + 1], garden[i][j]);
            }
        }

        // Calculate up boundary
        for (int j = 0; j < w; j++) {
            up[0][j] = garden[0][j];
            for (int i = 1; i < d; i++) {
                up[i][j] = max(up[i - 1][j], garden[i][j]);
            }
        }

        // Calculate down boundary
        for (int j = 0; j < w; j++) {
            down[d - 1][j] = garden[d - 1][j];
            for (int i = d - 2; i >= 0; i--) {
                down[i][j] = max(down[i + 1][j], garden[i][j]);
            }
        }

        int max_capacity = 0;
        for (int i = 1; i < d - 1; i++) {
            for (int j = 1; j < w - 1; j++) {
                int capacity = min({left[i][j], right[i][j], up[i][j], down[i][j]}) - garden[i][j];
                if (capacity > 0) {
                    max_capacity = max(max_capacity, capacity);
                }
            }
        }

        cout << max_capacity << endl;
    }

    return 0;
}