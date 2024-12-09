#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

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
    int k;
    long long l, r;
    cin >> k >> l >> r;

    // Calculate the number of ways to select k different tours of the same length
    long long ways = 0;
    for (int i = 1; i <= k; i++) {
        ways = (ways + power(r-l+1, k-i) * power(r-l, i-1)) % MOD;
    }

    cout << ways << endl;

    return 0;
}