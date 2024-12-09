#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
int n;
long long x;
long long a[100500];
map<long long, long long> st;
set<long long> second;
long long first(long long a, long long k) {
  if (k == 0) return 1;
  long long res = first(a, k / 2);
  res = (res * res) % mod;
  if (k % 2) res = (res * a) % mod;
  return res;
}
int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  long long ans = first(x, sum - a[n - 1]);
  long long m = a[n - 1];
  for (int i = 0; i < n; i++) a[i] = m - a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    st[a[i]]++;
    second.insert(1ll * a[i]);
  }
  for (__typeof(second.begin()) it = second.begin(); it != second.end(); it++) {
    long long y = *it;
    if (st[y] >= x) {
      st[y + 1] += st[y] / x;
      st[y] %= x;
      second.insert(y + 1);
    }
  }
  long long k;
  for (__typeof(second.begin()) it = second.begin(); it != second.end(); it++) {
    if (st[*it]) {
      k = min(m, *it);
      break;
    }
  }
  if (*second.begin() == 0 && st[0]) {
    k = 0;
  }
  ans = (ans * first(x, k)) % mod;
  cout << ans << endl;
  return 0;
}
