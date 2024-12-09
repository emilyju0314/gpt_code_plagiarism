#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int x, p;
    cin >> x >> p;

    double dp[1000001]; // dp[i] stores the expected number of turns to find Takahashi when his coordinate is i
    dp[0] = 0;

    for(int i = 1; i <= x; i++) {
        double p_prob = (double) p / 100.0;
        double q_prob = 1.0 - p_prob;

        dp[i] = p_prob * dp[i-1] + q_prob * (dp[i-1] + 2);
    }

    cout << fixed << setprecision(7) << dp[x] << endl;

    return 0;
}