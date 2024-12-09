#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PI 3.14159265359
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll s = a[0] + a[1], x = 0;
  for (int i = 2; i < n; i++) x ^= a[i];
  if ((s - x) & 1) {cout << -1 << endl; return 0; }
  ll d = (s - x) / 2;
  if ((d & x) || (d < 0) || (d > a[0])) { cout << -1 << endl; return 0; }

  ll m = 1;
  m = m<<40;
  ll a0 = d;
  rep(_, 41) {
    if (m & x) {
      if (a0 + m <= a[0]) a0 += m;
    }
    m = m>>1;
  }
  if (a0 <= 0) { cout << -1 << endl; return 0; }

  cout << a[0] - a0 << endl;

  return 0;
}

/*
*/
