#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    long long a, b;
    cin >> a >> b;

    long long total = a + b;

    vector<long long> divisors;
    for (long long i = 1; i * i <= total; i++) {
        if (total % i == 0) {
            divisors.push_back(i);
            if (i != total / i) {
                divisors.push_back(total / i);
            }
        }
    }

    long long count = 0;
    for (auto d : divisors) {
        if (gcd(d, a) == 1) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}