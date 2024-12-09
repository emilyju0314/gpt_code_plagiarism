#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;

    vector<int> stages(n);
    for(int i = 0; i < n; i++) {
        cin >> stages[i];
    }

    vector<long long> dp(n, LLONG_MAX);
    dp[0] = min((long long)(stages[0] * r1 + r3), (long long)(stages[0] * r2 + r2));

    for(int i = 1; i < n; i++) {
        long long min_time = LLONG_MAX;
        long long curr_time = 0;

        for(int j = i-1; j >= 0; j--) {
            curr_time += d;
            curr_time += min((long long)(stages[i] * r1 + r3), (long long)(stages[i] * r2 + r2));

            if(j > 0) {
                curr_time += min((long long)(stages[j] * r1 + r3), (long long)(stages[j] * r2 + r2));
            }

            curr_time += dp[j];

            min_time = min(min_time, curr_time);
        }

        dp[i] = min_time;
    }

    cout << dp[n-1] << endl;

    return 0;
}