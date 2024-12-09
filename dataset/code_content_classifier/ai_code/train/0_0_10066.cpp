#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<string> ports(4);
    for (int i = 0; i < 4; i++) {
        cin >> ports[i];
    }

    vector<vector<int>> row_prefix(n, vector<int>(m, 0));
    vector<vector<int>> col_prefix(m, vector<int>(n, 0));
    int capacity = 0;

    // Calculate initial capacity
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ports[0][i] != ports[1][i]) {
                row_prefix[i][j]++;
            }
            if (ports[2][j] != ports[3][j]) {
                col_prefix[j][i]++;
            }
            capacity += (row_prefix[i][j] + col_prefix[j][i] > 0);
        }
    }
    cout << capacity << endl;

    // Process modifications
    while (q--) {
        char s;
        int l, r;
        cin >> s >> l >> r;
        l--; r--;

        if (s == 'L') {
            for (int i = l; i <= r; i++) {
                for (int j = 0; j < m; j++) {
                    row_prefix[i][j] = 1 - row_prefix[i][j];
                    capacity += (2 * row_prefix[i][j] - 1);
                }
            }
        } else if (s == 'R') {
            for (int i = l; i <= r; i++) {
                for (int j = 0; j < m; j++) {
                    row_prefix[i][j] = 1 - row_prefix[i][j];
                    capacity += (2 * row_prefix[i][j] - 1);
                }
            }
        } else if (s == 'U') {
            for (int i = l; i <= r; i++) {
                for (int j = 0; j < n; j++) {
                    col_prefix[j][i] = 1 - col_prefix[j][i];
                    capacity += (2 * col_prefix[j][i] - 1);
                }
            }
        } else if (s == 'D') {
            for (int i = l; i <= r; i++) {
                for (int j = 0; j < n; j++) {
                    col_prefix[j][i] = 1 - col_prefix[j][i];
                    capacity += (2 * col_prefix[j][i] - 1);
                }
            }
        }

        cout << capacity << endl;
    }

    return 0;
}