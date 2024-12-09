#include <iostream>
#include <vector>

using namespace std;

vector<int> getPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    
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
    
    return primes;
}

long long findSmallestNumberWithNDivisors(int n) {
    vector<int> primes = getPrimes(n);
    long long result = 1;
    
    for (int i = 0; i < n - 1; i++) {
        long long p = primes[i];
        while (p <= 1e18 / primes[i]) {
            p *= primes[i];
        }
        result *= p;
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    cout << findSmallestNumberWithNDivisors(n) << endl;
    
    return 0;
}