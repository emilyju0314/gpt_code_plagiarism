#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long sum_of_digits(long long x) {
    long long sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        while (true) {
            if (gcd(n, sum_of_digits(n)) > 1) {
                cout << n << endl;
                break;
            }
            n++;
        }
    }

    return 0;
}