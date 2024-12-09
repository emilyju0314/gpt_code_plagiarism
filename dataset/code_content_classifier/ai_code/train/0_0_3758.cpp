#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> danger(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> danger[i][j];
            danger[j][i] = danger[i][j]; // Since passages are bidirectional
        }
    }

    long long total_danger = 0;
    for (int i = 0; i < n; i++) {
        long long danger_sum = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                vector<int> curr_danger;
                for (int l = 0; l < n; l++) {
                    if (l != i && l != j) {
                        curr_danger.push_back(danger[i][l] + danger[j][l]);
                    }
                }
                sort(curr_danger.begin(), curr_danger.end(), greater<int>());
                for (int s = 0; s < k - 2; s++) {
                    danger_sum += curr_danger[s];
                }
            }
        }
        total_danger += danger_sum / 2;
    }

    cout << total_danger / n << endl;

    return 0;
}