#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long min_resistors(long long a, long long b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + min_resistors(b, a % b);
    }
}

int main() {
    long long a, b;
    cin >> a >> b;

    long long g = gcd(a, b);

    cout << min_resistors(a / g, b / g) << endl;

    return 0;
}