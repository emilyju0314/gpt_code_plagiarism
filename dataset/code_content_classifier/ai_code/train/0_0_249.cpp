
#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 1000000007

using namespace std;

unordered_map<int, int> primeFactors(int n) {
    unordered_map<int, int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) factors[n]++;
    return factors;
}

int main() {
    int N;
    cin >> N;

    vector<int> q(N);
    for (int i = 0; i < N; i++) {
        cin >> q[i];
    }

    long long result = 1;
    for (int i = 0; i < N; i++) {
        unordered_map<int, int> factors = primeFactors(q[i]);
        for (auto it = factors.begin(); it != factors.end(); ++it) {
            result = (result * it->second) % MOD;
        }
    }

    cout << result << endl;

    return 0;
}