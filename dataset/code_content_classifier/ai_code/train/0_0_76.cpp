#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, m, a, b, p, q;
    cin >> n >> m >> a >> b >> p >> q;

    long long gcd = __gcd(a, b);
    if ((m % gcd) != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long diff = q * b - p * a;
    long long x = ((m/gcd) * b - (q * b)) / (diff);
    long long y = ((p * a) - (m / gcd) * a) / (diff);

    long long ans = max(ceil(x /(double)q), ceil(y / (double)p));
    cout << ans << endl;

    return 0;
}