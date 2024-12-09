#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define MOD 998244353

using namespace std;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    string A, B;
    cin >> A >> B;

    int n = A.size();
    int k = count(A.begin(), A.end(), '1');

    vector<int> a_indices, b_indices;
    for (int i = 0; i < n; i++) {
        if (A[i] == '1') {
            a_indices.push_back(i);
        }
        if (B[i] == '1') {
            b_indices.push_back(i);
        }
    }

    long long Z = 1;
    for (int i = 1; i <= k; i++) {
        Z = (Z * i) % MOD;
    }
    Z = (Z * Z) % MOD;

    long long inv_sum = 0;
    for (int i = 0; i < k; i++) {
        inv_sum = (inv_sum + mod_pow(2, n - b_indices[i], MOD)) % MOD;
    }

    long long result = (Z * inv_sum) % MOD;
    cout << result << endl;

    return 0;
}