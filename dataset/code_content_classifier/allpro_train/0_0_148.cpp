#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<vector<int>>> F(N, vector<vector<int>>(5, vector<int>(2)));
    vector<vector<int>> P(N, vector<int>(11));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 2; k++) {
                cin >> F[i][j][k];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 11; j++) {
            cin >> P[i][j];
        }
    }

    int max_profit = INT_MIN;

    for (int mask = 1; mask < (1 << 10); mask++) {
        int curr_profit = 0;

        for (int i = 0; i < N; i++) {
            int open_periods = 0;

            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 2; k++) {
                    if (F[i][j][k] && (mask & (1 << (2 * j + k)))) {
                        open_periods++;
                    }
                }
            }

            curr_profit += P[i][open_periods];
        }

        max_profit = max(max_profit, curr_profit);
    }

    cout << max_profit << endl;

    return 0;
}