#include <iostream>

using namespace std;

const long long MOD = 998244353;
const long long BASE = 10e8 + 7;

long long mod(long long a, long long b) {
    return ((a % b) + b) % b;
}

long long calculate(int n) {
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += mod((i - i), MOD);
    }
    return mod(sum, BASE);
}

int main() {
    long long n;
    cin >> n;

    long long result = calculate(n);
    cout << result << endl;

    return 0;
}