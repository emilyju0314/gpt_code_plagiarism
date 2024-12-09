#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long power(long long base, long long exp) {
    if (exp == 0) {
        return 1;
    }
    long long half = power(base, exp / 2) % MOD;
    long long result = (half * half) % MOD;
    if (exp % 2 == 1) {
        result = (result * base) % MOD;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * (a[i] + 1)) % MOD;
    }

    cout << (ans - 1) << endl;

    return 0;
}