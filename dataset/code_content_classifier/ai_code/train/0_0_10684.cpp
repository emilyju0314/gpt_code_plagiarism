#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    int max_property = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    if (i != k && j != l) {
                        vector<int> values = {table[i][j], table[i][l], table[k][j], table[k][l]};
                        sort(values.begin(), values.end());
                        max_property = max(max_property, values[1]);
                    }
                }
            }
        }
    }

    cout << max_property << endl;

    return 0;
}