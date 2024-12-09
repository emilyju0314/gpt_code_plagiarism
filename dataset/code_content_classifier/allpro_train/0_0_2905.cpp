#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
    int q;
    cin >> q;

    while(q--) {
        int r, n;
        cin >> r >> n;

        vector<long long> f(n+1, 1);

        for(int i = 1; i <= n; i++) {
            for(int j = 2*i; j <= n; j += i) {
                f[j] = (f[j] + f[i]) % MOD;
            }
        }

        long long ans = 1;
        for(int i = 0; i < r; i++) {
            ans = (ans * f[n]) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}