#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    long long p, q;
    cin >> p >> q;

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long numerator = 1, denominator = 0;
    for (int i = n - 1; i >= 0; i--) {
        long long temp = numerator;
        numerator = denominator + a[i] * numerator;
        denominator = temp;
    }

    long long common = gcd(p, q);
    p /= common;
    q /= common;

    if (numerator == p && denominator == q) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}