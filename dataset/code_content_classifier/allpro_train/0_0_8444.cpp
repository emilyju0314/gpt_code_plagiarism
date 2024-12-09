#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    long long t, w, b;
    cin >> t >> w >> b;

    long long lcm = (w * b) / gcd(w, b);
    long long cycles = min(t / w, t / b);
    long long total = (t / lcm) * lcm + min(t % lcm + 1, lcm);

    long long numerator = cycles * lcm + min(total, t) - cycles * lcm;
    long long denominator = t;

    long long divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    cout << numerator << "/" << denominator << endl;

    return 0;
}