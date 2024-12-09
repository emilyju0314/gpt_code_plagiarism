#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int S, T, U, N, O, D;
    cin >> S >> T >> U >> N >> O >> D;

    vector<int> e(T), c(T), h(N), a(N);
    for (int i = 0; i < T; i++) {
        cin >> e[i] >> c[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> h[i] >> a[i];
    }

    vector<vector<int>> dp(D + 1, vector<int>(S + 1, -1));
    dp[0][S] = 0;

    for (int day = 1; day <= D; day++) {
        for (int strength = 0; strength <= S; strength++) {
            for (int training = 0; training < T; training++) {
                if (e[training] > strength) continue;
                int remaining_strength = min(S, strength + O) - e[training];
                for (int donut = 0; donut < N; donut++) {
                    if (a[donut] > c[training]) continue;
                    int new_strength = min(S, remaining_strength + O);
                    dp[day][new_strength] = max(dp[day][new_strength], dp[day - 1][strength] + h[donut]);
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= S; i++) {
        result = max(result, dp[D][i]);
    }

    cout << result << endl;

    return 0;
}