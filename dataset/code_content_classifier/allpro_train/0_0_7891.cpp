#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long common_divisor = a[0];
    for (int i = 1; i < n; i++) {
        common_divisor = gcd(common_divisor, a[i]);
    }

    int result = 0;
    for (long long i = 1; i * i <= common_divisor; i++) {
        if (common_divisor % i == 0) {
            result++;
            if (i != common_divisor / i) {
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}