#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;

int main() {
    ll n, k, a[200000];
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    ll ub = mod * mod, lb = -(mod * mod);
    while (ub - lb > 1) {
        ll mid = (ub + lb) / 2, cnt = 0;
        for (ll i = 0; i < n; i++) {
            if (a[i] > 0)
                cnt += upper_bound(a, a + n, (long double)mid / a[i]) - a;
            else if (a[i] < 0)
                cnt += n - (lower_bound(a, a + n, (long double)mid / a[i]) - a);
            else if (mid >= 0)
                cnt += n;
            if (a[i] * a[i] <= mid)
                cnt--;
        }
        (cnt >= 2 * k ? ub : lb) = mid;
    }
    cout << ub << endl;
}
