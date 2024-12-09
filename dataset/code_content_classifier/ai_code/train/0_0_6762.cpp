#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> primes;

void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int m = 2 * n;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    sieve(b.back());

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (binary_search(primes.begin(), primes.end(), b[i])) {
            a[i] = b[n + i];
        } else {
            a[i] = b[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}