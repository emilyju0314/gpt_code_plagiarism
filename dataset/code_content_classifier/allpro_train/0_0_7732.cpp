#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

vector<long long> fib;

void calculateFib(int n) {
    fib.resize(n+1);
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i <= n; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
}

int main() {
    int n;
    cin >> n;

    calculateFib(n);

    long long ans = (2*(fib[n] + fib[n-1] - 1) % MOD) % MOD;
    cout << ans << endl;

    return 0;
}