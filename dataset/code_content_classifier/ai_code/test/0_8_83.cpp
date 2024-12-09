#include <iostream>

using namespace std;

const long long MOD = 998244353;

long long calculate(int n) {
    long long sum = 0;
    long long power = 1;
    for (int i = 1; i <= n; i++) {
        sum += (i - power + MOD) % MOD;
        power = (power * 10) % MOD;
    }
    return sum % 1000000007;
}

int main() {
    long long n;
    cin >> n;
    cout << calculate(n) << endl;
    return 0;
}