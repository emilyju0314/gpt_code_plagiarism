#include <bits/stdc++.h>
using namespace std;
int n, a[200000], m, b[400000], f[200000];
int F[200000];
long long go(int u, int d) {
  memcpy(F, f, n * sizeof(int));
  long long res = 0;
  int done = m;
  while (true) {
    --done;
    --F[u];
    if (F[u] < 0) return -1;
    if (done == 0) break;
    if (d == -1 && !u) {
      res += a[1] - a[0];
      d = -d;
      u = 1;
    } else if (d == 1 && u == n - 1) {
      res += a[n - 1] - a[n - 2];
      d = -d;
      u = n - 2;
    } else {
      res += abs(a[u] - a[u + d]);
      u += d;
    }
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", b + i);
    --b[i];
    ++f[b[i]];
  }
  if (m == 1) {
    puts("0");
    return 0;
  }
  set<long long> s;
  for (int i = 1; i + 1 < n - 1; ++i) {
    if (f[i] > f[i + 1]) s.insert(go(i, -1));
    if (f[i] < f[i + 1]) s.insert(go(i + 1, 1));
  }
  for (int i = 0; i < n; ++i)
    if (f[i]) {
      s.insert(go(i, 1));
      break;
    }
  for (int i = n - 1; i >= 0; --i)
    if (f[i]) {
      s.insert(go(i, -1));
      break;
    }
  bool is = f[0] == f[n - 1] && n > 3;
  for (int i = 2; i + 1 < n && is; ++i) is = is && f[i] == f[1];
  if (is) {
    for (int i = 1; i + 2 < n; ++i)
      if (a[i + 1] - a[i] != a[2] - a[1]) {
        puts("-1");
        return 0;
      }
  }
  s.insert(go(1, 1));
  s.insert(go(1, -1));
  s.insert(go(n - 2, 1));
  s.insert(go(n - 2, -1));
  s.erase(-1);
  long long res;
  if (s.size() != 1)
    res = -1;
  else
    res = *s.begin();
  cout << res << endl;
  return 0;
}
