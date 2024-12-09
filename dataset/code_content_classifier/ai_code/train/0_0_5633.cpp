#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    long long n, m;
    cin >> n >> m;

    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++) {
            long long candies = i * i + j * j;
            if (candies % m == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}