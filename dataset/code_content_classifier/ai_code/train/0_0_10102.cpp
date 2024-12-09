#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    vector<int> div(1000001, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                if (div[j] > 0)
                    ans = (ans + (long long)div[j] * a[i]) % MOD;
                if (j * j != a[i] && div[a[i]/j] > 0)
                    ans = (ans + (long long)div[a[i]/j] * a[i]) % MOD;
            }
        }

        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                div[j] = (div[j] + 1) % MOD;
                if (j * j != a[i])
                    div[a[i] / j] = (div[a[i] / j] + 1) % MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}