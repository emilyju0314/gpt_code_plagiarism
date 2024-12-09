#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int p, q;
    cin >> p >> q;

    int divisor = gcd(p, q);
    q = q / divisor;

    int b = 2;
    while (q % b != 0) {
        b++;
    }

    cout << b << endl;

    return 0;
}