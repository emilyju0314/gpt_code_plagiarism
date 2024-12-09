#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> table(n, vector<int>(m, 0));

        for (int j = 0; j < n; j++) {
            string row;
            cin >> row;
            for (int k = 0; k < m; k++) {
                table[j][k] = row[k] - '0';
            }
        }

        vector<vector<int>> operations;

        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < m - 1; k++) {
                if (table[j][k] == 1) {
                    operations.push_back({j+1, k+1, j+2, k+1, j+2, k+2});
                    table[j][k] ^= 1;
                    table[j+1][k] ^= 1;
                    table[j+1][k+1] ^= 1;
                }
            }
        }

        cout << operations.size() << endl;
        
        for (auto& operation : operations) {
            for (int cell : operation) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    return 0;
}