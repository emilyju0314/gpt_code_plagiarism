#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        int cost = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    if (j + 1 < m && grid[i][j + 1] == '.') {
                        if (y < 2 * x) {
                            cost += y;
                            j++;
                        } else {
                            cost += x;
                        }
                    } else {
                        cost += x;
                    }
                }
            }
        }

        cout << cost << endl;
    }

    return 0;
}