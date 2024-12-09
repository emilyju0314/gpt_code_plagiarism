#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    vector<long double> dp(N, 0.0);

    for (int i = N - 1; i >= 0; i--) {
        dp[i] = max((long double)A[i], (long double)A[i] + 0.5 * dp[(i + 1) % N] + 0.5 * dp[(i - 1 + N) % N] - (long double)0.5 * B[i]);
    }

    cout << fixed << setprecision(12) << dp[0] << endl;

    return 0;
}