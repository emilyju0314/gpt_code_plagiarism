#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> divisors;

    for (long long i = 1; i * i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            long long j = n / i;
            if (j != i) {
                divisors.push_back(j);
            }
        }
    }

    int count = 0;

    for (long long a : divisors) {
        for (long long b : divisors) {
            if (n % (a * b) == 0) {
                long long c = n / (a * b);
                if (c >= b) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}