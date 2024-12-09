#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--; // Convert to 0-based indexing
        edges[x][y] = 1;
        edges[y][x] = 1;
    }

    int valid_count = 0;

    for (int i = 0; i < (1 << n); i++) {
        bool has_0 = false, has_1 = false, has_2 = false;
        bool valid = true;

        for (int j = 0; j < n; j++) {
            int number = (i >> j) & 1;

            if (number == 0) has_0 = true;
            if (number == 1) has_1 = true;
            if (number == 2) has_2 = true;

            for (int k = 0; k < n; k++) {
                if (edges[j][k] && number + ((i >> k) & 1) == 0) {
                    valid = false;
                    break;
                }
            }

            if (!valid) break;
        }

        if (valid && has_0 && has_1 && has_2) {
            valid_count++;
        }
    }

    cout << valid_count << endl;

    return 0;
}