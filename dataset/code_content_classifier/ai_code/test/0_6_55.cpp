#include <iostream>
#include <cmath>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long result = 1;
    base = base % MOD;
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
    cin >> k;

    long long result = power(6, pow(2, k) - 2);
    cout << result << endl;

    return 0;
}