#include <iostream>
#include <unordered_map>

#define ll long long

using namespace std;

unordered_map<ll, int> dp;

ll fib(ll n) {
    if (n <= 1) return n;
    if (dp.find(n) != dp.end()) return dp[n];

    ll k = n / 2;
    if (n % 2 == 0) {
        return dp[n] = (fib(k) * (2 * fib(k + 1) - fib(k))) % 10000;
    } else {
        return dp[n] = (fib(k) * fib(k) + fib(k + 1) * fib(k + 1)) % 10000;
    }
}

int main() {
    ll f;
    cin >> f;

    dp[0] = 0;
    dp[1] = 1;

    int pos = 0;
    while (true) {
        ll cur = fib(pos);
        if (cur == f) {
            cout << pos << endl;
            break;
        } else if (cur > f) {
            cout << -1 << endl;
            break;
        }
        pos++;
    }

    return 0;
}