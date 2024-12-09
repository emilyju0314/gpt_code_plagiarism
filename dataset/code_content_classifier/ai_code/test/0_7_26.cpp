#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;
}

int modularExponentiation(int base, int exponent) {
    int result = 1;
    base = base % MOD;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        exponent = exponent >> 1;
        base = (base * base) % MOD;
    }
    return result;
}

int countPermutations(int n) {
    int numerator = factorial(2 * n);
    int denominator = (factorial(n) * factorial(n)) % MOD;
    
    // (numerator / denominator) % MOD
    return (numerator * modularExponentiation(denominator, MOD - 2)) % MOD;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int result = countPermutations(n);
        cout << result << endl;
    }

    return 0;
}