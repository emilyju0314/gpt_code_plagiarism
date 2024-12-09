#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    long long count = 0;
    long long total_k_pow_n = 1;
    for (int i = 0; i < n; i++) {
        total_k_pow_n = (total_k_pow_n * k) % MOD;
    }

    long long inv_k = 1;
    for (int i = 0; i < n; i++) {
        inv_k = (inv_k * (k - 1)) % MOD;
    }

    for (int i = 0; i < n; i++) {
        long long points_original = h[i] == 1 ? total_k_pow_n : 0;
        long long points_new = h[i] == k ? total_k_pow_n : (inv_k * k) % MOD;

        count = (count + (points_new - points_original + MOD) % MOD) % MOD;
    }

    cout << count << endl;

    return 0;
}