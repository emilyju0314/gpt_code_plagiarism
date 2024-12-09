#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int a, b;
    cin >> a >> b;

    long long ans = 0;

    for(int k = 1; k <= a; k++) {
        long long minx = max(b + 1, (2*b + k - 1) / k);
        long long maxx = (a * b + k - 1) / k;

        if(minx <= maxx) {
            long long cnt = (maxx - minx + 1) % MOD;
            ans = (ans + ((minx + maxx) % MOD) * cnt % MOD * 500000004 % MOD) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}