#include <iostream>
#include <iomanip>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int m, n, x, k, l, y;
    cin >> m >> n >> x >> k >> l >> y;

    int gcd_mn = gcd(m, n);
    int gcd_kl = gcd(k, l);

    double res = 0.0;

    for (int i = 0; i <= y; i++) {
        int t = i + 1;
        int numerator = (m - 1) * x + 1;
        int denominator = n * t;

        double p1 = (double)numerator / denominator;

        numerator = (k - 1) * y - i;
        denominator = l * t;

        double p2 = (double)numerator / denominator;

        res += p1 * p2;
    }

    cout << fixed << setprecision(6) << 1 - res << endl;

    return 0;
}