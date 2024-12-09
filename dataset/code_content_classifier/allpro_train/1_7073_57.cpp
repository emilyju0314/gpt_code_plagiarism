#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

template<typename T>
T extgcd(T a, T b, T &x, T &y) {
    T d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

map<ll, int> prime_factor(ll n) {
    map<ll, int> ret;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n % 2 == 0) n *= 2;
    auto ma = prime_factor(n);

    vector<ll> factors;
    for (auto it = ma.begin(); it != ma.end(); ++it) {
        ll x = 1;
        for (int i = 0; i < it->second; i++)x *= it->first;
        factors.push_back(x);
    }

    int k = factors.size();
    ll ret = n - 1;
    for (int bit = 1; bit < (1 << k) - 1; bit++) {
        ll a = 1, b = 1;
        for (int i = 0; i < k; i++) {
            if (bit & (1 << i))a *= factors[i];
            else b *= factors[i];
        }

        ll x, y;
        extgcd(a, b, x, y);

        a *= x, b *= y;
        if (a < 0) a = -a;
        else b = -b;

        ret = min(ret, min(a, b));
    }

    cout << ret << endl;
    return 0;
}
