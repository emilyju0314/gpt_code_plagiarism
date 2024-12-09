#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k, T;
    cin >> n >> k >> T;

    string genome;
    cin >> genome;

    vector<int> ti(k);
    for (int i = 0; i < k; i++) {
        cin >> ti[i];
    }

    vector<vector<int>> risks(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cin >> risks[i][j];
        }
    }

    // Calculate total risks for each substring
    vector<int> totalRisks(1 << k, 0);
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (char c : genome.substr(i, k)) {
            mask |= 1 << (c - 'A');
        }

        for (int j = 0; j < k; j++) {
            if (mask & (1 << j)) {
                for (int l = 0; l < k; l++) {
                    if (mask & (1 << l)) {
                        totalRisks[mask] += risks[j][l];
                    }
                }
                totalRisks[mask] += ti[j];
            }
        }
    }

    // Find number of organisms with total risk not greater than T
    int result = 0;
    for (int i = 0; i < (1 << k); i++) {
        if (totalRisks[i] <= T) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}