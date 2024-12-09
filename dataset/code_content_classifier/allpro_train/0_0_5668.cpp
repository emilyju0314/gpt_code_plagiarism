#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    long long a;
    cin >> a;

    long long l = 1;
    long long r = 10;

    while (r % a != 0) {
        l *= 10;
        r = l * 10 - 1;
    }

    cout << l << " " << r << endl;

    return 0;
}