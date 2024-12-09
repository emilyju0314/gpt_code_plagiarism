#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007

using namespace std;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        long long ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> a(n, 0);
            bool good = true;

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    a[j] = c[j];
                }
            }

            for (int j = 0; j < n - 1; j++) {
                int val = (a[j] + a[j + 1] - b[j]) / 2;
                if (val < 0 || val > c[j]) {
                    good = false;
                    break;
                }
                a[j] = min(a[j], val);
                a[j + 1] = max(a[j + 1], val);
            }

            if (good && a[0] >= x) {
                ans = (ans + 1) % MOD;
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}