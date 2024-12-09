#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        long long specialNum = 1;
        for (int j = 0; j < k-1; j++) {
            specialNum = (specialNum + power(n, j)) % MOD;
        }
        cout << specialNum << endl;
    }

    return 0;
}