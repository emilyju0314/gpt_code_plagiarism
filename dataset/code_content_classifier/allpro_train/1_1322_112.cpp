#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
void solve() {
  int n, m, a[105], b[105], x, c[105];
  memset(b, 0, sizeof(b));
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    c[i] = a[i];
  }
  sort(c, c + n);
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    b[x - 1] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (a[j] > a[j + 1]) {
        if (b[j] == 1) swap(a[j], a[j + 1]);
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (a[i] != c[i]) ok = false;
  }
  if (ok)
    printf("YES\n");
  else
    printf("NO\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
