#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    double dp[n+1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = 2.0 * (1 - pow(1 - (double)p / (1000000000), i)) / p;
    }

    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dp[i] * i;
    }

    cout << fixed << setprecision(15) << sum << endl;

    return 0;
}