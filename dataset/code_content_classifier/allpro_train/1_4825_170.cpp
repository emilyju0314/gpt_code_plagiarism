#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int n;
ll m;
vector<int> a;

bool chk(int x)
{
  ll cnt = 0;
  rep(i, n)
  {
    int pos = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
    cnt += n - pos;
  }
  return cnt < m;
}

int main()
{
  cin >> n >> m;
  a.resize(n);
  rep(i, n)
    cin >> a[i];
  sort(a.begin(), a.end());
  int ng = 0, ok = 2 * 100000 + 1;
  while (ok - ng > 1)
  {
    int mid = (ok + ng) / 2;
    if (chk(mid))
      ok = mid;
    else
      ng = mid;
  }
  vector<ll> csum(n + 1, 0);
  rep(i, n)
    csum[i+1] = csum[i] + a[i];
  ll ans = 0;
  rep(i, n)
  {
    int pos = lower_bound(a.begin(), a.end(), ok - a[i]) - a.begin();
    ll cnt = n - pos;
    ans += csum[n] - csum[pos] + cnt * a[i];
    m -= cnt;
  }
  ans += m * ng;
  cout << ans << endl;
  return 0;
}