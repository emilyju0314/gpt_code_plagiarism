#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, ans = 0, l, r;
  scanf("%lld%lld%lld%lld", &n, &k, &l, &r);
  ll a[n];
  for(j = 0; j < n; ++j) scanf("%lld", &a[j]);
  vector < pair<ll, ll> > v1, v2;
  for(i = 0; i < 1 << n / 2; ++i) {
    ll now = 0, nown = 0;
    for(j = 0; j < n / 2; ++j) if(1 << j & i) {
      nown++, now += a[j];
    }
    pair<ll, ll> p = make_pair(nown, now);
    v1.push_back(p);
  }
  for(i = 0; i < 1 << (n + 1) / 2; ++i) {
    ll now = 0, nown = 0;
    for(j = 0; j < (n + 1) / 2; ++j) if(1 << j & i) {
      nown++, now += a[n / 2 + j];
    }
    pair<ll, ll> p = make_pair(nown, now);
    v2.push_back(p);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  vector < pair<ll, ll> >::iterator it;
  for(it = v1.begin(); it != v1.end(); ++it) {
    pair<ll, ll> p1 = make_pair(k - (*it).first, l - (*it).second);
    pair<ll, ll> p2 = make_pair(k - (*it).first, r - (*it).second);
    ans += upper_bound(v2.begin(), v2.end(), p2) - lower_bound(v2.begin(), v2.end(), p1);
  }
  printf("%lld\n", ans);
  return 0;
}
