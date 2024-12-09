#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6;
vector<int> fib(MAXN);
vector<int> prefix(MAXN);

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int m, l, r, k;
    cin >> m >> l >> r >> k;

    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % m;
    }

    prefix[0] = fib[0] % m;
    for (int i = 1; i < MAXN; i++) {
        prefix[i] = (prefix[i-1] + fib[i]) % m;
    }

    ll ans = 0;
    for (int i = l-1; i < r; i++) {
        int g = prefix[i] - (l > 1 ? prefix[l-2] : 0) + m;
        g %= m;
        ans = gcd(ans, g);
    }

    cout << ans << endl;

    return 0;
}