#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
int a[maxn], n, cnt[maxn];
bool check(int ini, int fin) {
  fill(cnt, cnt + n + 1, 0);
  if (fin < n / 2) {
    for (int i = ini; i <= fin; ++i) cnt[a[i]]++;
    for (int i = n - 1 - ini; i >= n - 1 - fin; --i) cnt[a[i]]--;
    for (int i = 1; i <= n; ++i) {
      if (cnt[i] != 0) return false;
    }
  } else {
    for (int i = ini; i <= fin; ++i) cnt[a[i]]++;
    for (int i = fin + 1; i <= n - 1 - ini; ++i) cnt[a[i]]--;
    for (int i = 1; i <= n; ++i) {
      if (cnt[i] < 0) return false;
    }
  }
  return true;
}
void solve(int& l, int& r) {
  l = -1, r = -1;
  for (int i = 0; i < n / 2; ++i) {
    if (a[i] != a[n - 1 - i]) {
      if (l == -1) l = i;
      r = i;
    }
  }
  int ini = r, fin = n - 1;
  while (ini < fin) {
    int mid = (ini + fin) >> 1;
    if (check(l, mid))
      fin = mid;
    else
      ini = mid + 1;
  }
  r = ini;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cout << fixed;
  cout.precision(10);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int odds = 0;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] & 1) odds++;
  }
  if (odds > 1) {
    cout << 0 << endl;
    return 0;
  }
  bool ispal = true;
  for (int i = 0; i < n; ++i) {
    if (a[i] != a[n - 1 - i]) ispal = false;
  }
  if (ispal) {
    cout << (long long)n * (n + 1) / 2 << endl;
    return 0;
  }
  int l1 = -1, r1 = -1, l2 = -1, r2 = -1;
  solve(l1, r1);
  reverse(a, a + n);
  solve(l2, r2);
  int temp = r2;
  r2 = n - 1 - l2, l2 = n - 1 - temp;
  long long ans = ((long long)l1 + 1) * (n - r1);
  ans += ((long long)l2 + 1) * (n - r2);
  ans -= ((long long)l1 + 1) * (n - r2);
  cout << ans << endl;
  return 0;
}
