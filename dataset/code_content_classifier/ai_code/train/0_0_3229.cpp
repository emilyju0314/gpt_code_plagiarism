#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rarity(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rarity[i][j];
        }
    }

    long long total_time = 0;
    long long min_time = LLONG_MAX;
    pair<int, int> optimal_point;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            total_time = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    total_time += rarity[x][y] * pow(abs(x + 1 - i), 2) + pow(abs(y + 1 - j), 2);
                }
            }
            if (total_time < min_time) {
                min_time = total_time;
                optimal_point = {i, j};
            }
        }
    }

    cout << min_time << endl;
    cout << optimal_point.first << " " << optimal_point.second << endl;

    return 0;
}