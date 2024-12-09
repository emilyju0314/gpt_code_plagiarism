#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        long long ans = 0;
        int power_of_n = 0;
        while (k > 0) {
            if (k % 2 == 1) {
                ans = (ans + power(n, power_of_n)) % MOD;
            }
            power_of_n++;
            k /= 2;
        }

        cout << ans << endl;
    }

    return 0;
}