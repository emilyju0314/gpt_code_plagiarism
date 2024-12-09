#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> pots(2*N);
    for (int i = 0; i < 2*N; i++) {
        cin >> pots[i];
    }

    sort(pots.begin(), pots.end());

    vector<double> dp(N+1);
    for (int i = N; i >= 1; i--) {
        int num_pots = 2*N - i;
        dp[i] = dp[i+1] + (double)pots[num_pots-1];
        dp[i] = max(dp[i], (dp[i+1]*(double)(num_pots-1) + pots[num_pots-2])/(double)num_pots);
    }

    cout << fixed << setprecision(10) << dp[1] << endl;

    return 0;
}