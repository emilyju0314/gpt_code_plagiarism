#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int factorial(int n) {
    int result = 1;
    for(int i = 1; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

int modularExponentiation(int base, int exp) {
    int result = 1;
    base = base % MOD;
    while(exp > 0) {
        if(exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        exp = exp / 2;
        base = (base * base) % MOD;
    }
    return result;
}

int countPermutations(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = (2*i * (2*i - 1) * dp[i-1]) % MOD;
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << countPermutations(n) << endl;
    }
    return 0;
}