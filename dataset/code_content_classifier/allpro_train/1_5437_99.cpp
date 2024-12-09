#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, p, a, ans;
    cin >> n >> p;
    bool odd = false;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 1) odd = true;
    }
    if (!odd) {
        if (p == 0) ans = pow(2, n);
        else ans = 0;
    } else ans = pow(2, n-1);
    cout << ans << endl;
}