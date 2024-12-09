#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long f(long long a, long long b) {
    if (b == 0) {
        return 0;
    }
    return 1 + f(a, b - gcd(a, b));
}

int main() {
    long long x, y;
    cin >> x >> y;

    cout << f(x, y) << endl;

    return 0;
}