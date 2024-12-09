#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long powmod(long long base, long long exp, long long mod) {
    long long result = 1;
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
    int p, k;
    cin >> p >> k;

    if (k == 0) {
        cout << powmod(p, p-1, MOD) << endl;
    } else {
        vector<bool> visited(p);
        long long ans = 1;
        for (int i = 1; i < p; i++) {
            if (!visited[i]) {
                int j = i;
                int cycle_len = 0;
                while (!visited[j]) {
                    visited[j] = true;
                    j = (j * k) % p;
                    cycle_len++;
                }
                ans = (ans * powmod(p, cycle_len, MOD)) % MOD;
            }
        }
        cout << ans << endl;
    }

    return 0;
}