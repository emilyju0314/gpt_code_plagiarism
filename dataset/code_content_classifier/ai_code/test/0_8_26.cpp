#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Calculate factorial modulo MOD
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

// Calculate the answer for each test case
void solve() {
    int n;
    cin >> n;

    long long answer = 0;
    for (int i = 0; i <= n; ++i) {
        long long current = (factorial(2*n-2*i) * factorial(2*i)) % MOD;
        current = (current * (factorial(n+i) * factorial(n+i-1)) % MOD) % MOD;
        current = (current * (i == 0 ? 1 : 2)) % MOD; // Multiply by 2 if we have i > 0
        answer = (answer + current) % MOD;
    }

    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}