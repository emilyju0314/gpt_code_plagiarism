#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> factorize(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    int n;
    cin >> n;

    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    vector<int> subset;
    for (int i = 1; i <= n; i++) {
        vector<int> factors = factorize(i);
        int m = 1;
        for (int factor : factors) {
            m *= factor;
        }
        if (m * m <= n) {
            subset.push_back(i);
        }
    }

    cout << subset.size() << endl;
    for (int num : subset) {
        cout << num << " ";
    }

    return 0;
}