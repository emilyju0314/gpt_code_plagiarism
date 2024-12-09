#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rarity(n, vector<int>(m));
    vector<long long> sum_of_squares(n + 1, 0);
    vector<long long> distance_squares(m + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rarity[i][j];
            sum_of_squares[i + 1] = sum_of_squares[i] + rarity[i][j];
            distance_squares[j + 1] = distance_squares[j] + rarity[i][j];
        }
    }

    long long min_time = 1e18;
    pair<int, int> point;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            long long time = 0;
            for (int k = 0; k < n; k++) {
                time += rarity[k][0] * pow(abs(i - k), 2);
            }
            for (int k = 0; k < m; k++) {
                time += rarity[n-1][k] * pow(abs(j - k), 2);
            }
            if (time < min_time) {
                min_time = time;
                point = {i, j};
            }
        }
    }

    cout << min_time << endl;
    cout << point.first << " " << point.second << endl;

    return 0;
}