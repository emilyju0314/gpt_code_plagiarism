#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long countPermutations(int n) {
    vector<int> dp(n+1, 1);
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] * 1LL * i * (i-1)) % MOD;
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << countPermutations(n) << endl;
    }

    return 0;
}