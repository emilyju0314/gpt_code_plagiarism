#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> dp(n + 1, 0);
    long long sum = 0;

    dp[1] = 1;
    sum = dp[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = (i * dp[i - 1] + i) % m;
        sum = (sum + dp[i]) % m;
    }

    cout << sum << endl;

    return 0;
}