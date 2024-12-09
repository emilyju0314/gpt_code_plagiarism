#include <iostream>
using namespace std;

long long waysToFill(int n) {
    if(n % 2 != 0) {
        return 0;
    }

    long long dp[n+1];
    dp[0] = 1;
    dp[2] = 3;

    for(int i = 4; i <= n; i += 2) {
        dp[i] = dp[i-2] * 3;
        for(int j = 4; j <= i; j += 2) {
            dp[i] += 2 * dp[i-j];
        }
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << waysToFill(n) << endl;
    
    return 0;
}