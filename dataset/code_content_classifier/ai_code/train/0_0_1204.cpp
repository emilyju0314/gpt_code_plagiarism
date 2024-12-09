#include <iostream>
#include <cmath>

using namespace std;

long long f(long long b, long long n) {
    if (n < b) {
        return n;
    } else {
        return f(b, n / b) + n % b;
    }
}

int main() {
    long long n, s;
    cin >> n >> s;

    if (n == s) {
        cout << n << endl;
        return 0;
    }

    for (long long b = 2; b * b <= n; b++) {
        if (f(b, n) == s) {
            cout << b << endl;
            return 0;
        }
    }

    for (long long p = sqrt(n); p >= 1; p--) {
        long long b = (n - s) / p + 1;
        if (b >= 2 && f(b, n) == s) {
            cout << b << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}