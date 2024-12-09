#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<long long> f(n + 1, 0);
        vector<bool> isDivisor(n + 1, false);

        long long ans = 0;

        for (long long i = 1; i <= n; i++) {
            for (long long j = i; j <= n; j += i) {
                if (j > i && !isDivisor[j]) {
                    f[i] = j;
                    isDivisor[j] = true;
                    ans = (ans + j) % MOD;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}