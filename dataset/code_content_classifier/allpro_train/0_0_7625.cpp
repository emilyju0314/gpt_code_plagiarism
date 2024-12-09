#include <iostream>

using namespace std;

const int MOD = 998244353;

// Function to calculate the power a^b modulo MOD
long long power(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

// Function to calculate the binomial coefficient nCr modulo MOD
long long binomialCoeff(int n, int r) {
    long long num = 1, den = 1;
    for (int i = 0; i < r; i++) {
        num = (num * (n-i)) % MOD;
        den = (den * (i+1)) % MOD;
    }
    return (num * power(den, MOD-2)) % MOD;
}

int main() {
    int n;
    cin >> n;

    cout << binomialCoeff(2*(n-1), n) << endl;
    
    return 0;
}