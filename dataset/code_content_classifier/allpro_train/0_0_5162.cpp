#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> connections(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> connections[i][j];
        }
    }

    double result = 0.0;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> castle_liquid(n);
        double total_strength = 0.0;

        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                castle_liquid[j] = k;
            } else {
                castle_liquid[j] = 0;
            }
        }

        for (int j = 0; j < n; j++) {
            for (int l = j + 1; l < n; l++) {
                total_strength += castle_liquid[j] * castle_liquid[l] * connections[j][l];
            }
        }

        result = max(result, total_strength);
    }

    cout << fixed;
    cout.precision(12);
    cout << result << endl;

    return 0;
}