#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    int cnt = 0; // count of -1 in initial array
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            cnt++;
        }
    }
    
    long long dp = 0; // expected number of operations
    long long inv = 1; // inverse modulo
    for (int i = 1; i <= cnt; i++) {
        inv = (inv * i) % MOD; // calculate inverse modulo
    }
    inv = 1; // reset inv to 1
    
    for (int i = 0; i < cnt; i++) {
        long long ways = cnt; // number of ways to choose next position to fill (-1)
        long long not_ways = k - 1; // number of ways to choose value for current position
        
        dp = (dp + ways * not_ways * inv) % MOD;
        
        not_ways = (not_ways * (k - 1)) % MOD; // number of ways to choose value for following positions
        inv = (inv * cnt) % MOD;
        
        dp = (dp + not_ways * inv) % MOD;
    }
    
    cout << dp << endl;
    
    return 0;
}