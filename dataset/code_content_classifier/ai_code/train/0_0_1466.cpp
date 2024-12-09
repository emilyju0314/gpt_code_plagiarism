#include <iostream>
#include <vector>

using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> prime(n+1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

int nthPrime(int a, int d, int n) {
    vector<int> primes = sieveOfEratosthenes(1000000);
    int count = 0;
    int current = a;
    
    for (int i = 0; i < primes.size(); i++) {
        if (current % d == 0) {
            count++;
        }

        if (count == n) {
            return current;
        }
        
        current += d;
    }

    return -1;
}

int main() {
    while (true) {
        int a, d, n;
        cin >> a >> d >> n;

        if (a == 0 && d == 0 && n == 0) {
            break;
        }

        cout << nthPrime(a, d, n) << endl;
    }

    return 0;
}