#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

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

    while (t--) {
        long long m;
        cin >> m;

        cout << power(2, m-1) << endl;
    }

    return 0;
}