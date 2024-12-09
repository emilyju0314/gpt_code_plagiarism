#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    long long sum = 0;
    long long factorial = 1;

    for (int i = 1; i <= n - 1; i++) {
        factorial = (factorial * i) % MOD;
    }

    for (int i = 0; i < k; i++) {
        long long multiplier = (factorial * power(i + 1, MOD - 2)) % MOD;
        long long term = ((power(k - 1, MOD - 2) * multiplier) % MOD) * weights[i];
        sum = (sum + term) % MOD;
    }

    cout << sum << endl;

    return 0;
}