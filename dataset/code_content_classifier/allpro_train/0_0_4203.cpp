#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long power(int x, int n) {
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + power(i, k)) % MOD;
    }

    cout << ans << endl;

    return 0;
}