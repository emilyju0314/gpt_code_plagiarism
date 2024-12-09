#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> table(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < m; j++) {
                table[i][j] = row[j] - '0';
            }
        }

        vector<vector<int>> operations;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (table[i][j] == 1) {
                    operations.push_back({i+1, j+1, i+2, j+1, i+2, j+2});
                    table[i][j] = 1 - table[i][j];
                    table[i+1][j] = 1 - table[i+1][j];
                    table[i+1][j+1] = 1 - table[i+1][j+1];
                }
            }
        }

        cout << operations.size() << endl;
        for (auto op : operations) {
            for (auto cell : op) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    return 0;
}