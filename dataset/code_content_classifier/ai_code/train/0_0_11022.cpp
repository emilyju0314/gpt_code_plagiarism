#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    if (k > n || k == 1) {
        cout << power(m, n) << endl;
    } else if (k == n) {
        cout << power(m, (n + 1) / 2) << endl;
    } else if (k % 2 == 0) {
        cout << m << endl;
    } else {
        cout << m * m << endl;
    }

    return 0;
}