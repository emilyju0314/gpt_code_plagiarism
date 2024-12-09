#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    int count = 0;
    for (int i = 1; i < primes.size(); i++) {
        if (binary_search(primes.begin(), primes.end(), primes[i] + primes[i - 1] + 1)) {
            count++;
        }
    }

    if (count >= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}