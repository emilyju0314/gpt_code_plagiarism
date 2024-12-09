#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

long long fibonacci(int n){
    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    return dp[n];
}

int main() {
    int n, k;
    cin >> n >> k;

    // Calculate the sum of the first n elements of the sequence Ai(k)
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        sum = (sum + fibonacci(i) * pow(k, i)) % MOD;
    }

    cout << sum << endl;

    return 0;
}