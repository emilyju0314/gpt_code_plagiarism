#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;


int main() {
    int n, Q;
    cin >> n >> Q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    for (int j =0; j < Q; j++) {
        ll x; cin >> x;
        ll res = 0;
        int r = 0;
        ll s = 0;
        for (int l = 0; l < n; l++) {
            while (r < n && s + a[r] <= x) {
                s += a[r];
                r++;
            }

            res += r-l;
            if (l == r) r++;
            else s -= a[l];
        }
        cout << res << endl;
    }
}
