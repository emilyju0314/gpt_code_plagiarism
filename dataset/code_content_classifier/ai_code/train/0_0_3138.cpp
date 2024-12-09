#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(m), k(m), b(m), w(m), a(n+1), t(n+1);
    long long ans = 1;

    for (int i = 0; i < m; i++) {
        cin >> p[i] >> k[i] >> b[i] >> w[i];
    }

    long long base = 0;
    for (int i = 0; i < m; i++) {
        long long seed = b[i];
        base = w[i];
        for (int j = p[i-1]+1; j <= p[i]; j++) {
            t[j] = (seed % 2) + 1;
            a[j] = (seed % k[i]) + 1;
            seed = (seed * base + 233) % 1000000007;
        }
    }

    for (int i = 1; i <= n; i++) {
        int count = a[i];
        int idx = i;
        while (count--) {
            int j = idx;
            do {
                j = (j % n) + 1;
            } while (t[i] == t[j]);
            idx = j;
        }
        ans = (ans * ((idx ^ (i * i)) + 1)) % 1000000007;
    }

    cout << ans << endl;

    return 0;
}