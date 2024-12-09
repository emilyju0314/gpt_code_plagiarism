#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll l = 0, r = 0;
  int li = 0, ri = n - 1;
  rep(i, n) {
    if (l <= r) l += a[li++];
    else r += a[ri--];
  }
  cout << abs(l - r) << endl;
  return 0;
}
