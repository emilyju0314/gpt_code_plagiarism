#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    long long last = 0;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        int l = ((last + x) % n + 1);
        int r = ((last + y) % n + 1);

        if (l > r) {
            swap(l, r);
        }

        long long ans = a[l - 1];
        for (int j = l; j < r; j++) {
            ans = (ans * a[j]) % MOD;
        }

        cout << ans << endl;
        last = ans;
    }

    return 0;
}