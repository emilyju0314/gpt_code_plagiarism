#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> wall(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        wall[r-1][c-1] = 1;
    }

    double expected_time = 0.0;
    for (int i = 0; i < n; i++) {
        bool row_painted = false;
        for (int j = 0; j < n; j++) {
            if (wall[i][j] == 1) {
                row_painted = true;
                break;
            }
        }
        if (!row_painted) {
            expected_time += 1.0;
        }
    }

    for (int j = 0; j < n; j++) {
        bool col_painted = false;
        for (int i = 0; i < n; i++) {
            if (wall[i][j] == 1) {
                col_painted = true;
                break;
            }
        }
        if (!col_painted) {
            expected_time += 1.0;
        }
    }

    cout << fixed << setprecision(10) << expected_time << endl;

    return 0;
}