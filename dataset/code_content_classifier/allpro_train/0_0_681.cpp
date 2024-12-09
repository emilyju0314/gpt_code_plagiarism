#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) {
            break;
        }

        vector<int> sticks(N);
        for (int i = 0; i < N; i++) {
            cin >> sticks[i];
        }

        sort(sticks.begin(), sticks.end(), greater<int>());

        double max_volume = 0.0;
        for (int i = 0; i < N - 3; i++) {
            for (int j = i + 1; j < N - 2; j++) {
                for (int k = j + 1; k < N - 1; k++) {
                    for (int l = k + 1; l < N; l++) {
                        if (sticks[i] < sticks[j] + sticks[k] + sticks[l]) {
                            double s = 0.5 * (sticks[j] + sticks[k] + sticks[l]);
                            double volume = sqrt(s * (s - sticks[j]) * (s - sticks[k]) * (s - sticks[l]));

                            max_volume = max(max_volume, volume);
                        }
                    }
                }
            }
        }

        cout << fixed;
        cout.precision(6);
        cout << max_volume << endl;
    }

    return 0;
}