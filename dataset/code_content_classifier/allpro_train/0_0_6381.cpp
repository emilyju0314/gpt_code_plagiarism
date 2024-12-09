#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MOD = 998244353;

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;

    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

ll fact(int n, vector<ll>& factorial, ll p) {
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i) % p;
    }
}

ll nCr(ll n, ll r, vector<ll>& factorial, ll p) {
    if (r == 0 || r == n) return 1;
    
    return (factorial[n] * power(factorial[r], p-2, p) % p * power(factorial[n - r], p-2, p) % p) % p;
}

int main() {
    int N, K;
    ll P;
    cin >> N >> K >> P;

    vector<ll> factorial(N + 1, 1);
    fact(N, factorial, P);
    
    ll ans = 0;

    for (int i = 0; i <= K; i++) {
        ll temp = nCr(N, i, factorial, P) * power(N - 1, N - i, P) % P * (i % 2 == 0 ? 1 : -1) % P;
        if (temp < 0) temp += P;

        ans = (ans + temp) % P;
    }

    cout << ans << endl;

    return 0;
}