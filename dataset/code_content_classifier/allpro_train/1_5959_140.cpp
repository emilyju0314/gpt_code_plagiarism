#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int A, dp[20005];
    cin >> N;
    fill_n(dp, 20005, (1 << 30) - 1);
    dp[0] = 0;
    for(int p = 1; p < N; p++) {
        cin >> A;
        for(int i = N / 2; i >= 0; i--) {
            dp[p] = min(dp[p], dp[i] + A);
            dp[p - i] = min(dp[p - i], dp[i] + A);
        }
    }
    cout << dp[N / 2] << endl;
    return (0);
}

