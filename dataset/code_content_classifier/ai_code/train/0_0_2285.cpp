#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 16;

int main() {
    int n;
    cin >> n;

    vector<long long> fact(n+1, 1);
    for(int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = (ans + fact[n] * (n-1) / 2) % MOD;
    }

    cout << ans << endl;

    return 0;
}