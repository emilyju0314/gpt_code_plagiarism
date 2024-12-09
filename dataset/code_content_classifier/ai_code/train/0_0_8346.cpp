#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int n) {
    vector<int> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

int countAlmostPrimes(int n) {
    vector<int> is_prime = sieve(n);
    int count = 0;

    for (int i = 1; i <= n; i++) {
        int distinct_primes = 0;

        for (int j = 2; j <= n; j++) {
            if (is_prime[j] && i % j == 0) {
                distinct_primes++;

                while (i % j == 0) {
                    i /= j;
                }
            }
        }

        if (distinct_primes == 2 && i == 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    cout << countAlmostPrimes(n) << endl;

    return 0;
}