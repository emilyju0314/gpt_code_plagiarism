#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    long long l = lcm(C, D);
    long long count = B - A + 1;
    count -= (B / C) - ((A - 1) / C);
    count -= (B / D) - ((A - 1) / D);
    count += (B / l) - ((A - 1) / l);

    cout << count << endl;

    return 0;
}