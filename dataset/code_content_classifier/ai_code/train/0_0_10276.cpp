#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N, R;
    cin >> N >> R;

    vector<int> F(N), S(N), P(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i] >> S[i] >> P[i];
    }

    vector<double> dp(N+1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += P[j] / 100.0;
        }
        for (int j = 0; j < i; j++) {
            double reset_time = dp[j] + S[j];
            double continue_time = sum * F[i-1] + (1 - sum) * S[i-1];
            dp[i] = min(dp[i], max(reset_time, continue_time));
        }
    }

    cout << fixed << setprecision(9) << dp[N] << endl;

    return 0;
}