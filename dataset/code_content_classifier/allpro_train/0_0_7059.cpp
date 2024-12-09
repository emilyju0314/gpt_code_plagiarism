#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (1LL * result * base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<int> is_fixed(n, false);
    for (int i = 0; i < n; i++) {
        if (p[i] != 0) {
            is_fixed[p[i] - 1] = true;
        }
    }
    
    int count_gaps = 0;
    for (int i = 0; i < n; i++) {
        if (!is_fixed[i]) {
            count_gaps++;
        }
    }
    
    if (p[0] == 0) {
        p[0] = 1;
    }
    
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(i);
        }
    }
    
    for (int prime : primes) {
        if (is_fixed[prime - 1]) {
            for (int i = 0; i < n; i += prime) {
                if (p[i] == 0) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    
    int result = 1;
    for (int i = 0; i < count_gaps; i++) {
        result = (1LL * result * (i + 1)) % MOD;
    }
    
    cout << result << endl;

    return 0;
}