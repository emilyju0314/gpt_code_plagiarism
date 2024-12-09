#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;

    vector<vector<int>> land(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char cell;
            cin >> cell;
            land[i][j] = cell - '0';
        }
    }

    r1--; c1--; r2--; c2--;

    int min_cost = abs(r1 - r2) * abs(r1 - r2) + abs(c1 - c2) * abs(c1 - c2);

    // Try creating a tunnel between every pair of land cells and update min_cost
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (land[i][j] == 0) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (land[k][l] == 0) {
                            int tunnel_cost = abs(i - k) * abs(i - k) + abs(j - l) * abs(j - l);
                            int new_cost = min(abs(r1 - i) * abs(r1 - i) + abs(c1 - j) * abs(c1 - j)
                                               + abs(r2 - k) * abs(r2 - k) + abs(c2 - l) * abs(c2 - l),
                                               min_cost + tunnel_cost);
                            min_cost = min(min_cost, new_cost);
                        }
                    }
                }
            }
        }
    }

    cout << min_cost << endl;

    return 0;
}