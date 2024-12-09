#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long long a, b;
    cin >> a >> b;

    long long diff = abs(a - b);
    if (diff == 0) {
        cout << 0 << endl;
    } else {
        long long k = min(a % diff, diff - a % diff);
        cout << k << endl;
    }

    return 0;
}