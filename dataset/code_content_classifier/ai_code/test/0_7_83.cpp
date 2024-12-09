#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long result = 0;
    long long m = 998244353;

    long long t = 1;
    for (long long i = 1; i <= n; i *= 10, t *= 10) {
        long long j = min(n, i * 9);
        for (; i <= j; i++) {
            long long cur = (i - t) % m;
            result = (result + cur + m) % m;
        }
    }

    cout << result << endl;

    return 0;
}