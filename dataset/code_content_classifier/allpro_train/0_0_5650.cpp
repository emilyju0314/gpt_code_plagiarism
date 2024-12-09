#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 998244353;

vector<int> primes; // To store all prime numbers up to 10^5

// Function to generate all prime numbers up to n
void generatePrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
}

// Function to calculate the modular inverse of x modulo m
int modInverse(int x, int m) {
    int res = 1;
    x = x % m;
    for (int i = 0; i < m - 2; i++) {
        res = (res * x) % m;
    }
    return res;
}

int main() {
    generatePrimes(100000);
    int m;
    cin >> m;
    
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        int a, freq;
        cin >> a >> freq;
        
        long long sum_A = 0;
        for (int p : primes) {
            if (a % p == 0) {
                int k = 0;
                while (a % p == 0) {
                    a /= p;
                    k++;
                }
                sum_A = (sum_A + (long long)k * freq * p % MOD) % MOD;
            }
        }
        if (a > 1) {
            sum_A = (sum_A + (long long)freq * a % MOD) % MOD;
        }

        long long sum_B = (sum_A - freq + MOD) % MOD;
        
        ans = (ans + (sum_A * sum_B) % MOD) % MOD;
    }
    
    cout << ans << endl;

    return 0;
}