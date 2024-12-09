#include <iostream>
using namespace std;

long long gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    long long x, y;
    long long g = gcd(A, B, x, y);

    if (C % g != 0) {
        cout << -1 << endl;
    } else {
        x *= C / g;
        y *= C / g;
        cout << x << " " << y << endl;
    }

    return 0;
}