#include <iostream>

using namespace std;

int main() {
    long long n, p, w, d;
    cin >> n >> p >> w >> d;

    for (long long x = 0; x <= n; x++) {
        long long remaining = p - x * w;
        long long y = remaining / d;
        long long z = n - x - y;

        if (remaining % d == 0 && y >= 0 && z >= 0) {
            cout << x << " " << y << " " << z << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}