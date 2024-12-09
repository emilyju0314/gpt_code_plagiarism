#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 998244353;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, m, a;
    cin >> n >> m >> a;

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    long long ans = 1;
    for (int i = 0; i < m; i++) {
        int len;
        if (i == 0) {
            len = b[i];
        } else {
            len = b[i] - b[i - 1];
        }

        ans = (ans * power(a, len)) % MOD;
    }

    ans = (ans * power(a, n - b[m - 1])) % MOD;

    cout << ans << endl;

    return 0;
}