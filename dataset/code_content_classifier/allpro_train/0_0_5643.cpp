#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    long long ans = 0;
    
    for (int i = 1; i <= n; i++) {
        long long cnt = (long long)(n - i + 1) * i;
        ans = (ans + cnt) % MOD;
    }

    ans = (ans * 2 - n + MOD) % MOD;
    
    cout << ans << endl;

    return 0;
}