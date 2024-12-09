#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    long long N, P;
    cin >> N >> P;

    long long ans = 1;
    for (long long i = 2; i * i <= P; i++) {
        if (P % i == 0) {
            long long cnt = 0;
            while (P % i == 0) {
                P /= i;
                cnt++;
            }
            ans *= i;
        }
    }

    if (P > 1) {
        ans *= P;
    }

    cout << ans << endl;

    return 0;
}