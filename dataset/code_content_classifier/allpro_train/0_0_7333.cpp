#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

vector<vector<long long>> memo;

long long dp(long long i, long long dresses, long long x, long long k) {
    if (i == k) {
        return dresses;
    }
    
    if (memo[i][dresses] != -1) {
        return memo[i][dresses];
    }
    
    long long doubledDresses = 2 * dresses % MOD;
    long long eatOneDress = 0;
    
    if (dresses > 0) {
        eatOneDress = dp(i + 1, dresses - 1, x, k) % MOD;
    }
    
    long long result = ((doubledDresses + eatOneDress) * 500000004) % MOD; // (doubledDresses + eatOneDress) / 2 modulo 10^9 + 7
    
    return memo[i][dresses] = result;
}

int main() {
    long long x, k;
    cin >> x >> k;
    
    memo.assign(k + 1, vector<long long>(x + 1, -1));
    
    cout << dp(0, x, x, k) << endl;
    
    return 0;
}