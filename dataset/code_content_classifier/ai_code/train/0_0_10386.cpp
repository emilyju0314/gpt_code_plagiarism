#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        int M, K, R;
        cin >> M >> K >> R;

        vector<vector<vector<int>>> robots(N, vector<vector<int>>(3));
        for (int i = 0; i < N; i++) {
            cin >> robots[i][0] >> robots[i][1] >> robots[i][2];
        }

        vector<vector<int>> holes(M, vector<int>(5));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> holes[i][j];
            }
        }

        int min_energy = INT_MAX;
        for (int x = 1; x <= R; x++) {
            for (int y = 1; y <= R; y++) {
                for (int w = 1; w <= K; w++) {
                    bool is_valid = true;
                    for (int j = 0; j < M; j++) {
                        if (x >= holes[j][0] && x <= holes[j][2] && y >= holes[j][1] && y <= holes[j][3] && w == holes[j][4]) {
                            is_valid = false;
                            break;
                        }
                    }
                    if (is_valid) {
                        int energy = 0;
                        for (int i = 0; i < N; i++) {
                            energy += abs(x - robots[i][0]) + abs(y - robots[i][1]) + abs(w - robots[i][2]) - 1;
                        }
                        min_energy = min(min_energy, energy);
                    }
                }
            }
        }

        cout << min_energy << endl;
    }

    return 0;
}