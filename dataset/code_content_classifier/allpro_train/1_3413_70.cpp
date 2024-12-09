#include <bits/stdc++.h>
using namespace std;
int a[100005];
int lst[100005];
int nxt[100005], rw[100005];
int tol;
int s[100005];
int n, m;
long long go(int y) {
  int tp = 0;
  for (int p = lst[y]; p >= 0; p = nxt[p]) {
    if (rw[p] + 1 < m && a[rw[p] + 1] != y) s[tp++] = a[rw[p] + 1];
    if (rw[p] - 1 >= 0 && a[rw[p] - 1] != y) s[tp++] = a[rw[p] - 1];
  }
  if (tp == 0) return 0;
  long long sum = 0;
  for (int i = 0; i < tp; ++i) sum += abs(y - s[i]);
  sort(s, s + tp);
  int t = s[tp / 2];
  long long ns = 0;
  for (int i = 0; i < tp; ++i) ns += abs(t - s[i]);
  return sum - ns;
}
void solve() {
  long long res = 0;
  memset(lst, 0xff, sizeof(lst));
  cin >> n >> m;
  tol = 0;
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    a[i] = x;
    nxt[tol] = lst[x];
    lst[x] = tol;
    rw[tol] = i;
    ++tol;
  }
  for (int i = 1; i <= m - 1; ++i) res += abs(a[i] - a[i - 1]);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, go(i));
  cout << res - ans << endl;
}
int main() {
  solve();
  return 0;
}
