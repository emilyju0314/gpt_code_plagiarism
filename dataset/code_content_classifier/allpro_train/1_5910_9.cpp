#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    
    auto dig = [&](long long x) {
        int ret = 0;
        while (x) {
            ++ret;
            x /= 10;
        }
        return ret;
    };

    while (tc--) {
       int a, b, c;
       cin >> a >> b >> c;

       long long g = 1;
       while (dig(g) < c) g *= 10;

       long long x = g, y = g;
       while (dig(x) < a) x *= 2;
       while (dig(y) < b) y *= 3;

       cout << x << " " << y << '\n';
    }
}
