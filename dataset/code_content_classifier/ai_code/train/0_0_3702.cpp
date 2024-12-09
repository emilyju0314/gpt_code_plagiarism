#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    long long ans = 0;
    for(int i = K; i <= N+1; i++) {
        long long min_sum = 1LL * i * (i - 1) / 2;
        long long max_sum = 1LL * (2 * N - i + 1) * i / 2;
        ans += (max_sum - min_sum + 1) % MOD;
        ans %= MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}