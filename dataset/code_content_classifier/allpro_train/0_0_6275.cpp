#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> inc(n + 1, 1);
    vector<long long> dec(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        inc[i] = (inc[i - 1] + dec[i - 1]) % MOD;
        dec[i] = inc[i - 1];
    }

    long long ans = (inc[n] + dec[n]) % MOD;
    cout << ans << endl;

    return 0;
}