#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> table(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> table[i][j];
            }
        }

        int operations = 0;
        vector<vector<int>> ops;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (table[i][j] == '1') {
                    ops.push_back({i + 1, j + 1, i + 1, j + 2, i + 2, j + 1});
                    table[i][j] = '0';
                    table[i][j + 1] = (table[i][j + 1] == '0') ? '1' : '0';
                    table[i + 1][j] = (table[i + 1][j] == '0') ? '1' : '0';
                    operations++;
                }
            }
        }

        cout << operations << endl;
        for (auto op : ops) {
            for (int i = 0; i < 6; i++) {
                cout << op[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}