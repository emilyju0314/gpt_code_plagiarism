#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int n;
vector<int> a(10);
vector<vector<vector<int>>> dp;

int countNumbers(int pos, int sum, int limit) {
    if (pos == n) {
        return sum >= 1;
    }
    
    if (dp[pos][sum][limit] != -1) {
        return dp[pos][sum][limit];
    }
    
    long long ans = 0;
    int maxDigit = limit ? 9 : a[pos];
    
    for (int digit = 0; digit <= maxDigit; digit++) {
        ans += countNumbers(pos + 1, sum + (digit >= a[pos]), limit | (digit < maxDigit)) % MOD;
        ans %= MOD;
    }
    
    return dp[pos][sum][limit] = ans;
}

int main() {
    cin >> n;
    
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    
    dp.assign(n, vector<vector<int>>(n+1, vector<int>(2, -1)));
    
    cout << countNumbers(0, 0, 0) << endl;
    
    return 0;
}